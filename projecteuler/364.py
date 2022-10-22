mod=10**8+7

from tqdm import tqdm
from collections import Counter
cnt = Counter()

def one_neighbor_vacant(i: int,occupied: list) -> bool:
    if set([i-1,i]).isdisjoint(occupied) or set([i+1,i]).isdisjoint(occupied):
        return True
    return False

def neighbor_vacant(i: int,occupied: list) -> bool:
    if set([i-1,i,i+1]).isdisjoint(occupied):
        return True
    return False

def naive(n: int,occupied: list = []) -> int:
    if len(occupied) == n:
        cnt[occupied[0]] += 1
        return 1

    ret: int = 0
    flag1: bool = True
    flag2: bool = True
    for i in range(n):
        if neighbor_vacant(i,occupied):
            flag1 = False
            ret += naive(n,occupied+[i])

    if flag1:
        for i in range(n):
            if one_neighbor_vacant(i,occupied):
                flag2 = False
                ret += naive(n,occupied+[i])

    if flag1 and flag2:
        for i in range(n):
            if i not in occupied:
                ret += naive(n,occupied+[i])

    return ret

fact = [1]*1_000_001
for i in range(1,len(fact)):
    fact[i] = fact[i-1]*i%mod

def inv(k:int) -> int:
    return pow(k,mod-2,mod)

def nck(n:int, k:int) -> int:
    return fact[n]*inv(fact[n-k])*inv(fact[k])%mod

def sub_solve(n: int,one: int,two: int) -> int:
    zero = n - one - two*2
    if one+two+1==zero:
        # like #..#..#.#
        return nck(one+two,two)*fact[zero]*pow(2,two,mod)*fact[two]*fact[one+two]%mod
    elif one+two==zero:
        if one < 1:
            return 0
        return 2*nck(one+two-1,two)*fact[zero]*pow(2,two,mod)*fact[two+1]*fact[one+two-1]%mod
    elif one+two-1==zero:
        if one < 2:
            return 0
        return nck(one+two-2,two)*fact[zero]*pow(2,two,mod)*fact[two+2]*fact[one+two-2]%mod
    assert False

def solve(n: int)  -> int:
    ret = 0

    for two in tqdm(range(n)):
        for one in range(max(0,(n-two*3)//2-3),min(n,(n-two*3)//2+3)):
            # one*2+two*3+(1,-1,0)=n
            if abs(n-one*2-two*3) <= 1:
                ret += sub_solve(n,one,two)

    return ret%mod
    

if __name__ == "__main__":
    #for i in range(1,13):
    #    print(f"{i}:{naive(i)},{solve(i)}")
    print(solve(1_000_000))