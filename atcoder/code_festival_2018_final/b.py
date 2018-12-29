n,m=map(int,input().split())
r=list(map(int,input().split()))
r.sort()
ma=max(r)
l=[0]*(max(n,ma)+1)
from math import log10,ceil
for i in range(1,1+max(n,ma)):
    l[i] = l[i-1]+log10(i)

ex=0
ex+=l[n]
ex-=n*log10(m)
ex-=m*l[r[0]]
for i in range(1,m):
    ex-=(m-i)*(l[r[i]]-l[r[i-1]])
print(ceil(-ex))
