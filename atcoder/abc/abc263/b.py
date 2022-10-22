n=int(input())
p=list(map(int,input().split()))
d=[0]*(n+1)
for i in range(n-1):
    d[i+2]=d[p[i]]+1
print(d[n])