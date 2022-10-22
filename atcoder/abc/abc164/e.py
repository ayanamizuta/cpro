n,m,s=map(int,input().split())
u,v,a,b=[],[],[],[]
for _ in range(m):
  u_in,v_in,a_in,b_in=map(int,input().split())
  u.append(u_in)
  v.append(v_in)
  a.append(a_in)
  b.append(b_in)
c,d=[],[]
edges=[[] for _ in range(n)]
for _ in range(m):
  c_in,d_in=map(int,input().split())
  c.append(c_in)
  d.append(d_in)
  edges[c_in-1].append(d_in-1)
  edges[d_in-1].append(c_in-1)

dp=[[int(1e18) for _ in 10000] for _ in range(n+1)]

def dfs(start,t,silver):
  if dp[start][silver]<=t:
    return
  silver_pre=0
  while silver<10002:
    for i in range(silver_pre,min(silver+1,10000)):
      dp[start][i]=min(dp[start][i],t)
    for x in edges[start-1]:
      dfs(x+1,t,s)
    t+=d[start-1]
    silver+=c[start-1]
dfs(1,0,s)

for i in range(2,n+1):
  print(min(*dp[i]))