n,m=map(int,input().split())
l = list(range(1,n+1))

def inc(l):
    for i in range(n-1,-1,-1):
        if l[i]<=m and (i-l[i])>=(n-m):
            tmp=l[i]+1
            for j in range(i,n):
                l[j]=tmp-i+j
            return True
    return False

print(*l)
while inc(l):
    print(*l)

