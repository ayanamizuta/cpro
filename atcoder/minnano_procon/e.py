import numpy as np
mod=998244353
n,m=map(int,input().split())
a=[0]*n
for i in range(n):
    a[i] = list(map(int,input().split()))
rnk=0
for i in range(m):
    
rnk = np.linalg.matrix_rank(np.array(a,dtype='int32'))
x=n-rnk
y=m-rnk

def powe(n,e):
    ret=1
    b=n
    while e>0:
        if e%2==1:
            ret*=b
        b=b*b
        ret%=mod
        b%=mod
        e//=2
    return ret

table = [[0]*301 for x in range(301)]

def inv(q):
    return powe(q,mod-2)

for i in range(301):
    table[i][0]=1
for p in range(301):
    for q in range(1,p+1):
        table[p][q] = (table[p][q-1]*(p-q+1)*inv(q))%mod
def nck(p,q):
    return table[p][q]
ret=0
for s in range(1,rnk+1):
    odds=0
    for t in range(1,s+1):
        if t%2==1:
            odds+=nck(s,t)
            odds%=mod
    ret+=nck(rnk,s)*odds*powe(2,rnk-s)
    ret%=mod
print((ret*powe(2,x)*powe(2,y))%mod)
