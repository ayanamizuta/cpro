n,m=map(int,input().split())

edges=[]
for i in range(m):
    a,b=map(int,input().split())
    edges.append((a,b))
    edges.append((b,a))

def conn(v1,v2):
    return (v1,v2) in edges

import itertools
ret=0
for x in itertools.permutations(list(range(1,n+1))):
    for i in range(n-1):
        if not conn(x[i],x[i+1]) or x[0]!=1:
            break
        if i==n-2:
            ret+=1

print(ret)
