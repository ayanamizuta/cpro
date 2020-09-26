n,s = map(int,input().split())
a = list(map(int,input().split()))
dp = [[0 for _ in range(s+1)] for _ in range(n+1)]

mod = 998244353

def power(n,e):
    ret = 1
    b = n
    while e:
        if e % 2 != 0:
            ret *= b
        ret %= mod
        b *= b
        b %= mod
        e //= 2
    return ret

def div(n1,n2):
    return n1*power(n2,mod-2)%mod

dp[0][0] = power(2,n)
for i in range(1,n+1):
    for j in range(s+1):
        dp[i][j] = dp[i-1][j] % mod
    for j in range(s+1):
        if j >= a[i-1]:
            dp[i][j] += div(dp[i-1][j-a[i-1]],2)

print(dp[-1][-1] % mod)