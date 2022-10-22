n=int(input())
a__=list(map(int,input().split()))
if sum(a__)!=0:
    print(-1)
    exit()
    
a_ = [0]*n
for i in range(1,n):
    a_[i]=a_[i-1]+a__[i-1]
su=sum(a_)
if su%n!=0:
    print(-1)
    exit()
ave=sum(a_)//n
a_ = [a_[i]-ave for i in range(n)]

a = [0]*n
for i in range(1,n):
    a[i]=a[i-1]+a_[i-1]
mini = min(a)
print(sum([a[i]-mini for i in range(n)]))
