n,m=map(int,input().split())
a=list(map(int,input().split()))

cumsum=[0]*(n+1)
for i in range(n):
    cumsum[i+1]=cumsum[i]+a[i]

ret_cand=0
for i in range(m):
    ret_cand+=(i+1)*a[i]

ret=ret_cand
for i in range(n-m):
    su = cumsum[i+m] - cumsum[i]
    ret_cand -= su
    ret_cand+=m*a[i+m]
    if ret_cand>ret:
        ret=ret_cand

print(ret)