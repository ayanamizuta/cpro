a,b,c,d,e=map(int,input().split())
from collections import Counter
cnt=Counter()
cnt[a]+=1
cnt[b]+=1
cnt[c]+=1
cnt[d]+=1
cnt[e]+=1
if cnt.most_common()[0][1]==3 and cnt.most_common()[1][1]==2:
    print("Yes")
else:
    print("No")