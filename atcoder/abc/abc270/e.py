import heapq
n,k=map(int,input().split())
a=list(map(int,input().split()))
a_with_index = [[a_,i] for i,a_ in enumerate(a)]
a_with_index.sort()

index = 0
elim_max = 0
live=n
last_idx=0
while True:
    mina,mina_index = a_with_index[index]
    index+=1
    mina_diff=mina-elim_max
    if mina_diff*live<=k:
        k-=mina_diff*live
        live-=1
        elim_max=mina
        last_idx=mina_index
    else:
        diff = k//live
        k-=diff*live
        elim_max+=diff
        last_idx=mina_index
        break

#print(a,elim_max)
for i in range(n):
    a[i]-=min(a[i],elim_max)

for i in range(last_idx,n):
    if k:
        a[i]-=1
        k-=1

for i in range(last_idx):
    if k:
        a[i]-=1
        k-=1
print(*a)
