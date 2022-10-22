n,x_=map(int,input().split())
a=list(map(int,input().split()))
a.sort(reverse=True)


def dist(standard,init):
    def dist_sub(begin,end,min_left,min_right):
        if begin > standard:
            return [min_left,min(min_right,begin-standard)]
        if begin <= standard <= end:
            return [0,0]
        if standard >= begin:
            min_left=min(min_left,standard-begin)
        if standard >= end:
            min_left=min(min_left,standard-end)
        if standard <= begin:
            min_right=min(min_right,begin-standard)
        if standard <= end:
            min_right=min(min_right,end-standard)
        return dist_sub(2*begin,2*end+x_,min_left,min_right)
    return dist_sub(init,init,10**18,10**18)

dists = [None]*(n-1)
for i in range(1,n):
    dists[i-1] = dist(a[0],a[i]) + [i]
dists.sort(key=lambda x:x[0],reverse=True)
min_dist = 0
for x in dists:
    min_dist = max(min_dist,x[1])
max_left=0
#print(dists)
for i,x in enumerate(dists):
    if i:
        max_left = max(max_left,dists[i-1][1])
    min_dist = min(min_dist,dists[i][0]+max_left)

if min_dist < x_:
    print(0)
else:
    print(min_dist)