n=int(input())
a=list(map(int,input().split()))

#import random
#n=100000
#a=[random.randint(1,1000000000) for _ in range(n)]

import heapq
minv=min(a)
a=[-a_ for a_ in a]
heapq.heapify(a)

cnt=0
while len(a)!=1:
    maxv = -heapq.heappop(a)
    #print(maxv)
    if maxv%minv!=0:
        heapq.heappush(a,-(maxv%minv))
        minv = maxv%minv
    cnt+=1

print(cnt)

    
    