n,k = map(int,input().split())
k = abs(k)
a = [0]*(2*n+1)
for i in range(2*n+1):
    a[i] = min(i-1,2*n+1-i)
ret = 0
for i in range(2,2*n+1):
    if k+i < 2*n+1:
        ret += a[i]*a[k+i]
print(ret)