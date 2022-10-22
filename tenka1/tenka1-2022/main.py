import os
import sys
import random
import json
import time
import urllib.request
import urllib.error
from log import logger
from copy import deepcopy
from multiprocessing import Pool

# ゲームサーバのアドレス / トークン
GAME_SERVER = os.getenv('GAME_SERVER', 'https://2022contest.gbc.tenka1.klab.jp')
TOKEN = os.getenv('TOKEN', 'YOUR_TOKEN')

N = 5
Dj = [+1, 0, -1, 0]
Dk = [0, +1, 0, -1]


# ゲームサーバのAPIを叩く
def call_api(x: str) -> dict:
    url = f'{GAME_SERVER}{x}'
    # 5xxエラーの際は100ms空けて5回までリトライする
    for i in range(5):
        logger.info(url)
        try:
            with urllib.request.urlopen(url) as res:
                return json.loads(res.read())
        except urllib.error.HTTPError as err:
            if 500 <= err.code and err.code < 600:
                logger.info(err.code)
                time.sleep(0.1)
                continue
            else:
                raise
        except ConnectionResetError as err:
            logger.info(err)
            time.sleep(0.1)
            continue
    raise Exception('Api Error')


def get_game_ids() -> int:
    while True:
        join = call_api(f'/api/join/{TOKEN}')
        if join['status'] == 'ok' and join['game_ids']:
            logger.info(f"join game id: {join['game_ids']}")
            return join['game_ids']
        time.sleep(1)

    # start APIを呼び出し練習試合のgame_idを取得する
    mode = 0
    delay = 0

    start = call_api(f'/api/start/{TOKEN}/{mode}/{delay}')
    if start['status'] == 'ok' or start['status'] == 'started':
        return [start['game_id']]

    raise Exception(f'Start Api Error : {start}')


# d方向に移動するように移動APIを呼ぶ
def call_move(game_id: int, d: int) -> dict:
    return call_api(f'/api/move/{TOKEN}/{game_id}/{d}')


# ゲーム状態クラス
class State:
    def __init__(self, field, agent):
        self.field = deepcopy(field)
        self.agent = deepcopy(agent)

    # idxのエージェントがいる位置のfieldを更新する
    # 値を返す。
    # 0: 既に自陣
    # 1: 自陣以外が半塗りになる
    # 2: 半塗りが自陣全塗りに代わる
    # 3: 崩壊
    # 4: 無が自陣に代わる
    def paint(self, idx: int) -> int:
        i, j, k, _ = self.agent[idx]
        if self.field[i][j][k][0] == -1:
            # 誰にも塗られていない場合はidxのエージェントで塗る
            self.field[i][j][k][0] = idx
            self.field[i][j][k][1] = 2
            return 4
        elif self.field[i][j][k][0] == idx:
            # idxのエージェントで塗られている場合は完全に塗られた状態に上書きする
            ret = 2
            if self.field[i][j][k][1] == 2:
                ret = 0
            self.field[i][j][k][1] = 2
            return ret
        elif self.field[i][j][k][1] == 1:
            # idx以外のエージェントで半分塗られた状態の場合は誰にも塗られていない状態にする
            self.field[i][j][k][0] = -1
            self.field[i][j][k][1] = 0
            return 3
        else:
            # idx以外のエージェントで完全に塗られた状態の場合は半分塗られた状態にする
            self.field[i][j][k][1] -= 1
            return 1

    # エージェントidxをd方向に回転させる
    # 方向については問題概要に記載しています
    def rotate_agent(self, idx: int, d: int):
        self.agent[idx][3] += d
        self.agent[idx][3] %= 4

    # idxのエージェントを前進させる
    # マス(i, j, k)については問題概要に記載しています
    def move_forward(self, idx: int):
        i, j, k, d = self.agent[idx]
        jj = j + Dj[d]
        kk = k + Dk[d]
        if jj >= N:
            self.agent[idx][0] = i // 3 * 3 + (i % 3 + 1) % 3  # [1, 2, 0, 4, 5, 3][i]
            self.agent[idx][1] = k
            self.agent[idx][2] = N - 1
            self.agent[idx][3] = 3
        elif jj < 0:
            self.agent[idx][0] = (1 - i // 3) * 3 + (4 - i % 3) % 3  # [4, 3, 5, 1, 0, 2][i]
            self.agent[idx][1] = 0
            self.agent[idx][2] = N - 1 - k
            self.agent[idx][3] = 0
        elif kk >= N:
            self.agent[idx][0] = i // 3 * 3 + (i % 3 + 2) % 3  # [2, 0, 1, 5, 3, 4][i]
            self.agent[idx][1] = N - 1
            self.agent[idx][2] = j
            self.agent[idx][3] = 2
        elif kk < 0:
            self.agent[idx][0] = (1 - i // 3) * 3 + (3 - i % 3) % 3  # [3, 5, 4, 0, 2, 1][i]
            self.agent[idx][1] = N - 1 - j
            self.agent[idx][2] = 0
            self.agent[idx][3] = 1
        else:
            self.agent[idx][1] = jj
            self.agent[idx][2] = kk

    # エージェントが同じマスにいるかを判定する
    def is_same_pos(self, a: list[int], b: list[int]) -> bool:
        return a[0] == b[0] and a[1] == b[1] and a[2] == b[2]

    # idxのエージェントがいるマスが自分のエージェントで塗られているかを判定する
    def is_owned_cell(self, idx: int) -> bool:
        i = self.agent[idx][0]
        j = self.agent[idx][1]
        k = self.agent[idx][2]
        return self.field[i][j][k][0] == idx

    # 全エージェントの移動方向の配列を受け取り移動させてフィールドを更新する
    # -1の場合は移動させません(0~3は移動APIのドキュメント記載と同じです)
    def move(self, move: list[int]):
        # エージェントの移動処理
        for idx in range(6):
            if move[idx] == -1:
                continue
            self.rotate_agent(idx, move[idx])
            self.move_forward(idx)

        # フィールドの更新処理
        ret = None
        for idx in range(6):
            if move[idx] == -1:
                continue
            ok = True
            for j in range(6):
                if idx == j or move[j] == -1 or not self.is_same_pos(self.agent[idx], self.agent[j]) or self.is_owned_cell(idx):
                    continue
                # 移動した先にidx以外のエージェントがいる場合は修復しか行えないのでidxのエージェントのマスではない場合は更新しないようにフラグをfalseにする
                ok = False
                break

            if not ok:
                if idx==0:
                    ret = 0
                continue
            ret_ = self.paint(idx)
            if idx==0:
                ret=ret_
        return ret

    def is_another_near(self) -> bool:
        for j in range(1,6):
            if self.is_same_pos(self.agent[0], self.agent[j]):
                return True
        return False

def solve_game(game_id):
    next_d = random.randint(0, 3)
    two_continue = 0
    while True:
        # 移動APIを呼ぶ
        move = call_move(game_id, next_d)
        logger.info('status = {}'.format(move['status']))
        if move['status'] == "already_moved":
            continue
        elif move['status'] != 'ok':
            break
        logger.info('turn = {}'.format(move['turn']))
        logger.info('score = {} {} {} {} {} {}'.format(move['score'][0], move['score'][1], move['score'][2], move['score'][3], move['score'][4], move['score'][5]))
        # 4方向で移動した場合を全部シミュレーションする
        best_c = -1
        best_d = []
        flip_ok = False
        another_near = [False]*4
        for d in range(4):
            m = State(move['field'], move['agent'])
            local_score = m.move([d, -1, -1, -1, -1, -1])
            if m.is_another_near():
                another_near[d]=True
            for d_ in range(4):
                if another_near[d]:
                    break
                m_ = State(m.field,m.agent)
                m_.move([d_, -1, -1, -1, -1, -1])
                if m_.is_another_near():
                    another_near[d]=True
            # 自身のエージェントで塗られているマス数をカウントする
            # 直前のマスが自陣でない場合、そのマスに戻る

            c = local_score
            """for i in range(6):
                for j in range(N):
                    for k in range(N):
                        if m.field[i][j][k][0] == 0:
                            c += 1"""
            if d==2 and c>0:
                flip_ok=True
            # 最も多くのマスを自身のエージェントで塗れる移動方向のリストを保持する
            if c > best_c:
                best_c = c
                best_d = [d]
            elif c == best_c:
                best_d.append(d)
        # 最も多くのマスを自身のエージェントで塗れる移動方向のリストからランダムで方向を決める
        another_vacances = [i for i in range(4) if not another_near[i]]
        if set(best_d).intersection(set(another_vacances)):
            next_d = random.choice(list(set(best_d).intersection(set(another_vacances))))
        else:
            if another_vacances:
                next_d = random.choice(another_vacances)
            else:
                next_d = random.choice([0,1,2,3])

        if flip_ok and not another_near[2]:
            next_d=2
        if next_d==2:
            two_continue+=1
        else:
            two_continue=0
        if two_continue>5:
            next_d = random.choice([0,1,3])
            two_continue=0


if __name__ == "__main__":
    while True:
        game_ids = get_game_ids()
        with Pool(len(game_ids)) as p:
            logger.info(f"games {game_ids} start")
            print("games start")
            p.map(solve_game, game_ids)
            print("games finish")
            logger.info(f"games {game_ids} finish")
    