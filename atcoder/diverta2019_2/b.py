n=int(input())
if n==1:
    print(1)
    exit()
x=[0]*n
y=[0]*n
for i in range(n):
    x[i],y[i]=map(int,input().split())

from collections import Counter
cnt = Counter()
    
for i in range(n):
    for j in range(n):
        if i!=j:
            cnt[str((x[j]-x[i],y[j]-y[i]))]+=1

print(n-cnt.most_common()[0][1])
