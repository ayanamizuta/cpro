n,m=map(int,input().split())
a=[list(input()) for _ in range(2*n)]

result = [[0,i+1] for i in range(2*n)]

def battle(a,b):
  if a==b:
    return [0,0]
  if a=='G'and b=='C' or a=='C'and b=='P' or a=='P'and b=='G':
    return [1,0]
  return [0,1]

for i in range(m):
  for j in range(n):
    a_idx = result[2*j][1]-1
    b_idx = result[2*j+1][1]-1
    result_in = battle(a[a_idx][i],a[b_idx][i])
    result[2*j][0]-=result_in[0]
    result[2*j+1][0]-=result_in[1]
  result.sort()

for x in result:
  print(x[1])