n=int(input())
p=list(map(int,input().split()))

p_after=[(n+p[i] - i)%n for i in range(n)]
from collections import Counter
cnt=Counter()
for i,p_ in enumerate(p):
    pp = p_-i
    cnt[(n+pp-1)%n]+=1
    cnt[(n+pp)%n]+=1
    cnt[(n+pp+1)%n]+=1
print(cnt.most_common()[0][1])