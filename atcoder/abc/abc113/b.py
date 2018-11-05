n=int(input())
t,a=map(int,input().split())
l = list(map(int,input().split()))
min_ = 100*100000
ret=0
for i in range(n):
    x = l[i]
    if min_ > abs(a-t+x*0.006):
        ret = i+1
        min_ = min(min_,abs(a-t+x*0.006))

print(ret)
