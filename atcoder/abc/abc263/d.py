n,l,r=map(int,input().split())
a=list(map(int,input().split()))

dpl=[0]*(n+1)
for i in range(1,n+1):
    dpl[i]=min(dpl[i-1]+a[i-1],l*i)

a=a[::-1]

dpr=[0]*(n+1)
for i in range(1,n+1):
    dpr[i]=min(dpr[i-1]+a[i-1],r*i)

ret=n*10**10
for i in range(n+1):
    ret=min(ret,dpl[i]+dpr[n-i])

print(ret)