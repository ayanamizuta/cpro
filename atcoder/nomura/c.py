n = int(input())
a = list(map(int,input().split()))
if a[-1] == 0:
    print(-1)
    exit()

if a[0] == 1 and n == 0:
    print(1)
    exit()
elif a[0] >= 1:
    print(-1)
    exit()

par = [0]*(n+1)
par[0] = 1
for i in range(1,n+1):
    par[i] = par[i-1]*2-a[i]
    if par[i] < 0:
        print(-1)
        exit()

ret = a[-1]
suc = a[-1]
for i_ in range(n):
    i = n-1-i_
    ret += min(suc,par[i]) + a[i]
    suc = min(suc,par[i]) + a[i]

print(ret)