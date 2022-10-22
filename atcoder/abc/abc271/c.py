n=int(input())
a=list(map(int,input().split()))
a.sort()

def ok(mid):
    cntr={}
    thres=0
    for i,a_ in enumerate(a):
        if a_<=mid:
            cntr[a_]=1
    n_ = len(list(cntr.keys()))
    return (n_+(n-n_)//2)>=mid

lb=0
ub=10000000
while lb<ub:
    mid=(lb+ub)//2
    if ok(mid):
        lb=mid+1
    else:
        ub=mid
print(lb-1)