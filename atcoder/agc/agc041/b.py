n,m,v,p=map(int,input().split())
a = list(map(int,input().split()))
a.sort(reverse=True)
reva = [a[0] - x for x in a]
ub = a[0]
lb = a[-1]

from bisect import *

def ok(val):
    i = bisect_left(reva,a[0]-val)
    val = a[i]
    if v-(min(n-i,v)) < p and a[p-1] <= a[i] + m:
        return True
    l = v - (p-1) - (n - i)
    if a[i]+m < a[p-1]:
        return False
    if sum(list(map(lambda x:min(a[i]+m-x,m),a[p-1:i]))) >= l*m:
        return True
    return False

while ub > lb:
    mid = (ub+lb)//2
    if ok(mid):
        ub=mid
    else:
        lb=mid+1

print(len(list(filter(lambda x:x >= lb,a))))