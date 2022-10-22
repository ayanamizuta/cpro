import sys
sys.setrecursionlimit(210000)
n,m=map(int,input().split())
a=list(map(lambda x:int(x)-1,input().split()))
b=list(map(lambda x:int(x)-1,input().split()))
edges = [[] for _ in range(n)]
for i in range(m):
    a_,b_ = a[i],b[i]
    edges[a_].append((b_,i))
    edges[b_].append((a_,i))
visited = [False]*m
table = [0]*m

def dfs(v):
    for v_next,index in edges[v]:
        if visited[index]:
            continue
        visited[index]=True
        table[index]= 1 if v==a[index] else 0
        #print(index,v,v_next,table[index])
        dfs(v_next)

for i in range(n):
    dfs(i)


print("".join(map(str,table)))