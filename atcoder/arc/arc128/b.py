t=int(input())

def solve(r,g,b):
  if len(set([r%3,g%3,b%3]))==3:
    print(-1)
  elif r%3==g%3 and g%3==b%3:
    mid = min(r,g,b)^r^g^b^max(r,g,b)
    print(mid)
  elif r%3==g%3:
    print(max(g,r))
  elif r%3==b%3:
    print(max(r,b))
  elif g%3==b%3:
    print(max(g,b))

for _ in range(t):
  solve(*list(map(int,input().split())))