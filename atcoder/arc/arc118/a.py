t,n=map(int,input().split())
lb=1
ub=1000_000_000_000_000

def ok(m):
    dif = m*(100+t)//100-m
    return dif >= n

while lb<ub:
    mid=(lb+ub)//2
    if ok(mid):
        ub = mid
    else:
        lb=mid+1

print(lb*(100+t)//100-1)