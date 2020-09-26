a = [[0]*3]*3
for i in range(3):
  a[i] = list(map(int,input().split()))

n = int(input())

for _ in range(n):
  m = int(input())
  for i in range(3):
    for j in range(3):
      if m == a[i][j]:
        a[i][j] = -1
        
for i in range(3):
  if a[i][0] == -1 and a[i][1] == -1 and a[i][2] == -1:
    print("Yes")
    exit(0)
  if a[0][i] == -1 and a[1][i] == -1 and a[2][i] == -1:
    print("Yes")
    exit(0)
if a[0][0] == -1 and a[1][1] == -1 and a[2][2] == -1:
  print("Yes")
  exit(0)
if a[0][2] == -1 and a[1][1] == -1 and a[2][0] == -1:
  print("Yes")
  exit(0)
print("No")