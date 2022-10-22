t=int(input())

def digit(n):
    return len(str(n))

def rep(n,k):
    up = n // 10**(digit(n)//k*(k-1))
    up_cand=int(str(up)*k)
    if n>=up_cand:
        return up_cand
    return int(str(up-1)*k)

def solve():
    n=int(input())
    d=digit(n)
    ret=int("9"*(d-1))
    for k in range(2,d+1):
        if d % k == 0:
            ret = max(ret,rep(n,k))
    print(ret)

for _ in range(t):
    solve()