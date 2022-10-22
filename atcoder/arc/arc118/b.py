k,n,m=map(int,input().split())
a = list(map(int,input().split()))
b = [0]*k
for i,a_ in enumerate(a):
    r = a_*m//n
    if abs(r*n - a_*m) > abs((r+1)*n - a_*m):
        b[i]=r+1
    else:
        b[i]=r

sb = sum(b)
if sb==m:
    print(" ".join(map(str,b)))
    exit()

import heapq


if sb<m:
    heap = [[1000000000,i] for i in range(k)]
    for i,b_ in enumerate(b):
        if b_*n < a[i]*m:
            heap[i] = [b_*n - a[i]*m,i]
    heapq.heapify(heap)
    for i in range(m-sb):
        d,j = heapq.heappop(heap)
        b[j]+=1
    print(" ".join(map(str,b)))
    exit()

heap = [[10000000000,i] for i in range(k)]
for i,b_ in enumerate(b):
    if b_*n > a[i]*m:
        heap[i] = [a[i]*m-b_*n,i]
heapq.heapify(heap)
for i in range(sb-m):
    _,j = heapq.heappop(heap)
    b[j]-=1
print(" ".join(map(str,b)))
exit()