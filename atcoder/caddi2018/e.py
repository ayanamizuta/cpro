n = int(input())
a = list(input().split())
adel = [0]*(n+1)
ll = [0]*(n+1)
ll[n] = 0
for i in range(n+1,0,-1):
    target = a[i]
    nbh = a[i+1]
    delta = delta(target,nbh)
    if delta >= 0:
        ll[i] = ll[i+1]
        adel[i] = delta
    else:
        idx = bs()
        



ret = 2*200000*200000*60
for i in range(n+1):
    ret = min(ret,ll[i]+ll_rev[i])
print(ret)