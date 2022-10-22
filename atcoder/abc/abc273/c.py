from collections import Counter
n=int(input())
a=list(map(int,input().split()))

cnt=Counter()
for a_ in a:
    cnt[a_]+=1
v = list(set(a))
v.sort(reverse=True)
for i in range(n):
    if len(v)>i:
        print(cnt[v[i]])
    else:
        print(0)