n=int(input())

def ok1(lb,ub):
    print(f"? {lb} {ub} 1 {n}")
    t=int(input())
    return t

def ok2(lb,ub):
    print(f"? 1 {n} {lb} {ub}")
    t=int(input())
    return t

lb=1
ub=n
cur=n-1
while lb<ub:
    mid=(ub+lb)//2
    res = ok1(lb,mid)
    if res>cur//2:
        lb=mid+1
        cur-=res
    else:
        ub=mid
        cur=res
i=lb

lb=1
ub=n
cur=n-1
while lb<ub:
    mid=(ub+lb)//2
    res = ok2(lb,mid)
    if res>cur//2:
        lb=mid+1
        cur-=res
    else:
        ub=mid
        cur=res
j=lb

print(f"! {i} {j}")    