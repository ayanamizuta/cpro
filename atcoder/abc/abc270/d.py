n,k=map(int,input().split())
a=list(map(int,input().split()))
dp=[0]*(10001)

for i in range(1,n+1):
    for a_ in a:
        if a_ <= i:
            dp[i]=max(dp[i],a_+i-a_-dp[i-a_])

print(dp[n])