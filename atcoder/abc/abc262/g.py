n=int(input())
a=list(map(int,input().split()))

n=50
a=list(range(1,n+1))

dp = [[[[0 for _ in range(n+1)]for _ in range(n+1)]for _ in range(n+1)]for _ in range(n+1)]

for de in range(n):
    for i in range(n-de):
        j=i+de
        for k in range(1,n+1):
            for l in range(k,n+1):
                if k==l:
                    dp[i][j][k][l]=a[i:j+1].count(k)
                elif i==j:
                    dp[i][j][k][l]=1 if k<=a[i]<=l else 0
                else:
                    dp[i][j][k][l]=dp[i][j][k][l-1]
                    for m in range(i,j+1):
                        if a[m]==l:
                            if m==i:
                                dp[i][j][k][l]=dp[i+1][j][k][l]+1
                            elif m==j:
                                dp[i][j][k][l]=dp[i][j-1][k][l]+1
                            else:
                                for n_ in range(k,l+1):
                                    dp[i][j][k][l]=max(dp[i][j][k][l],1+dp[i][m-1][k][n_]+dp[m+1][j][n_][l])

print(dp[0][n-1][1][n])