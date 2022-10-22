import sys
sys.setrecursionlimit(300000)
n,x,y=map(int,input().split())
edges=[[] for _ in range(n)]

for _ in range(n-1):
    u,v=map(int,input().split())
    u-=1
    v-=1
    edges[u].append(v)
    edges[v].append(u)

x-=1
y-=1

visited=[False]*n
res = []

def dfs(v):
    if visited[v]:
        return False
    visited[v]=True
    if v==y:
        res.append(v)
        return True
    for next_v in edges[v]:
        next_v_res = dfs(next_v)
        if next_v_res:
            res.append(v)
            return True

dfs(x)
res = [res_+1 for res_ in res]
print(*res[::-1])
