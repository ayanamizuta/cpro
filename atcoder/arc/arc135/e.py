t = int(input())
mod = 998244353


def solve():
    n, x = map(int, input().split())
    a_before = x
    div_before = x
    idx = 2
    while True:
        a_after = a_before + (idx - a_before % idx)
        div_after = a_after // idx
        if div_before == div_after:
            print(idx)
            exit()
        a_before = a_after
        div_before = div_after
        idx += 1


for _ in range(t):
    solve()
