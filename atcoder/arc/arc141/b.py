n,m=map(int,input().split())

mod=998244353
if n > 60:
    print(0)
    exit()
if n==1:
    print(m%mod)
    exit()

dp = [[0 for _ in range(61)] for _ in range(61)]

for i in range(1,61):
    dp[1][i]=2**(i-1)

for i in range(2,61):
    for j in range(2,61):
        dp[i][j] = sum(dp[i-1][k] for k in range(j))*(2**(j-1))


digit = 1
b_digit=0
ret=0
while digit <= m:
    if 2*digit <= m:
        ret+=digit*sum(dp[n-1][k] for k in range(1,1+b_digit))
    else:
        ret+=(m-digit+1)*sum(dp[n-1][k] for k in range(1,1+b_digit))
    ret%=mod
    b_digit+=1
    digit*=2
print(ret)