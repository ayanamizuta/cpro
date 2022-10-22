import sys
sys.setrecursionlimit(200000)
from collections import Counter
n=int(input())
a=[list(map(int,input().split())) for _ in range(n)]

cnts_fst=[Counter() for _ in range(n)]
cnts_snd=[Counter() for _ in range(n)]

def dfs(i,j,val):
    if i+j==n-1:
        cnts_fst[i][val^a[i][j]]+=1
        return
    dfs(i+1,j,val^a[i][j])
    dfs(i,j+1,val^a[i][j])

def dfs_snd(i,j,val):
    if i+j==n-1:
        cnts_snd[i][val]+=1
        return
    dfs_snd(i-1,j,val^a[i][j])
    dfs_snd(i,j-1,val^a[i][j])

dfs(0,0,0)
dfs_snd(n-1,n-1,0)
ret=0
for i in range(n):
    for j in cnts_fst[i].keys():
        ret+=cnts_fst[i][j]*cnts_snd[i][j]
print(ret)
