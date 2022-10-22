n=int(input())
c=[list(map(int,input().split())) for _ in range(1<<n)]
dp = [{} for _ in range(1<<n)]

def depth(b):
    cnt=0
    while b:
        cnt+=1
        b>>=1
    return cnt

def interval(b):
    d=depth(b)
    width=1<<(n-d+1)
    l=(b-(1<<(d-1)))*width
    return (l,l+width)
bits=(1<<n)-1
while bits:
    if bits>>(n-1):
        l,r=interval(bits)
        dp[bits][l]=0
        dp[bits][r-1]=0
    else:
        d=n-depth(bits)
        l,r=interval(bits)
        maxl=max(map(lambda tup:tup[1]+c[tup[0]][d-1],dp[(bits<<1)].items()))
        maxr=max(map(lambda tup:tup[1]+c[tup[0]][d-1],dp[(bits<<1)+1].items()))
        
        for i in range(l,r):
            if i < (l+r)//2:
                dp[bits][i]=dp[(bits<<1)][i]+maxr
            else:
                dp[bits][i]=dp[(bits<<1)+1][i]+maxl

    bits-=1
ret=0
for i in range(1<<n):
    ret=max(ret,dp[1][i]+c[i][-1])
print(ret)
