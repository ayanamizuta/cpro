n,k=map(int,input().split())
a=list(map(int,input().split()))
mod = 1000000007

def digit(n):
    ret = 0
    while n>0:
        n//=2
        ret+=1
    return ret

for i in range(n):
    a[i] = digit(a[i])

ret = 0

k = min(k,sum(a))

dp_zero = [[0]*(k+1)  for _ in range(n)]
dp      = [[0]*(k+1)  for _ in range(n)]

for i in range(n):
    if i == 0:
        dp[0][0:min(a[0],k+1)] = [1] * min(a[0],k+1) 
        dp_zero[0][a[0]:max(a[0],k+1)] = [1] * (max(a[0],k+1) - a[0])
    else:
        for j in range(k+1):
            dp[i][j] = sum(dp[i-1][max(0,j-(a[i]-1)):j+1]) % mod
        for j in range(k+1):
            for l in range(a[i],j+1):
                dp_zero[i][j] += dp[i-1][j-l]
                dp_zero[i][j] %= mod
            for l in range(0,min(a[i]+1,j+1)):
                dp_zero[i][j] += dp_zero[i-1][j-l]
                dp_zero[i][j] %= mod

print((dp[-1][-1] + dp_zero[-1][-1]) % mod)
