a,b=map(int,input().split())
c,d=map(int,input().split())
e,f=map(int,input().split())
cnt=[0]*4
cnt[a-1]+=1
cnt[b-1]+=1
cnt[c-1]+=1
cnt[d-1]+=1
cnt[e-1]+=1
cnt[f-1]+=1
if max(cnt)<3:
    print("YES")
else:
    print("NO")
