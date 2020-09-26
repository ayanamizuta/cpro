mod = 998244353
a,b,c,d = map(int,input().split())
dp = [[0 for _ in range(d+1)] for _ in range(c+1)]

dp[a][b] = 1
if d > b:
    dp[a][b+1] = a
if c > a:
    dp[a+1][b] = b
for i in range(b+2,d+1):
    dp[a][i] = dp[a][i-1]*a%mod

for i in range(a+2,c+1):
    dp[i][b] = dp[i-1][b]*b%mod

for i in range(a+1,c+1):
    for j in range(b+1,d+1):
        dp[i][j] = (dp[i][j-1] * i % mod + dp[i-1][j] * j % mod - dp[i-1][j-1]*(i-1)*(j-1)%mod + mod) % mod

#print(dp)
print(dp[c][d] % mod)