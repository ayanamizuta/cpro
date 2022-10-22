n=int(input())
a=list(map(int,input().split()))
ret=[0]*n

std=a[0]
stdi=0
i=1
while i<n:
  if std<a[i]:
    std=a[i]
    stdi=i
    i+=1
    continue
  while i<n:
    if i<n-1 and a[i]>a[i+1]:
      i+=1
    else:
      ret[stdi]=1
      ret[i]=1
      stdi=i+1
      if stdi<n:
        std=a[stdi]
      i+=2
      break
print(*ret)
    