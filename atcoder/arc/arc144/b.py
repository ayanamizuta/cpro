n,a,b=map(int,input().split())
alist=list(map(int,input().split()))
alist.sort()

def ok(mini):
    sub=0
    plus=0
    for i in range(n):
        if alist[i]<mini:
            sub+=-(-(mini-alist[i])//a)
        else:
            plus+=(alist[i]-mini)//b
    return plus>=sub

lb = 1
ub = 10**9+2
while lb < ub:
    mid = (lb+ub)//2
    if ok(mid):
        lb=mid+1
    else:
        ub=mid

print(lb-1)