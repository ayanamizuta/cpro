n,k = map(int,input().split())
a = list(map(int,input().split()))
mod = 998244353
for kk in range(1,k+1):
    ret = 0
    for i in range(n):
        for j in range(i+1,n):
            ret += (a[i]+a[j])**kk
            ret %= mod
    print(ret)