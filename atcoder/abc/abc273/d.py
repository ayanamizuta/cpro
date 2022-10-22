from collections import defaultdict


h,w,r,c=map(int,input().split())
n=int(input())
rs,cs=[0]*n,[0]*n
mpc=defaultdict(list)
mpr=defaultdict(list)
for i in range(n):
    rs[i],cs[i]=map(int,input().split())
    mpc[cs[i]].append(rs[i])
    mpr[rs[i]].append(cs[i])
for key in mpc:
    mpc[key].sort()
for key in mpr:
    mpr[key].sort()


q=int(input())

def bdry(arr,pos,d):
    if arr[0]>pos:
        return (1,arr[0]-1)
    if arr[-1]<pos:
        return (arr[-1]+1,h) if d=="UD" else (arr[-1]+1,w)
    lb=0
    ub=len(arr)-1
    while lb<ub:
        mid=(lb+ub)//2
        if arr[mid]>pos:
            ub=mid
        else:
            lb=mid+1
    return (arr[lb-1]+1,arr[lb]-1)

#print("--------",bdry([1,4,8,12],9,"LR"))

def solve(d,l,r,c):
    if d in ["U","D"]:
        if not mpc.get(c):
            return (max(1,r-l),c) if d=="U" else (min(h,r+l),c) 
        r_left,r_right = bdry(mpc.get(c),r,"UD")
        return (max(r_left,r-l),c) if d=="U" else (min(r_right,r+l),c) 
    elif d in ["L","R"]:
        if not mpr.get(r):
            return (r,max(1,c-l)) if d=="L" else (r,min(w,c+l))
        c_left,c_right = bdry(mpr.get(r),c,"LR")
        return (r,max(c_left,c-l)) if d=="L" else (r,min(c_right,c+l))
for i in range(q):
    d,l=input().split()
    l=int(l)
    r,c=solve(d,l,r,c)
    print(r,c)


