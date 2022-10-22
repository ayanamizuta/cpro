n,m,k=map(int,input().split())
a=list(map(int,input().split()))

a.sort(reverse=True)
lacks=[0]*n
prefix=0

def lack(a_,b_):
    ret=0
    for i in range(33):
        if (a_ & (1<<(32-i))) and not (b_ & (1<<(32-i))):
            return (a_ % (1<<(33-i))) - (b_ % (1<<(33-i)))
    return 0


for i in range(32):
    for j in range(n):
        lacks[j]=lack((prefix*2+1)<<(29-i),a[j])
    lacks.sort()
    prefix=prefix<<1
    if sum(lacks[:k])<=m:
        prefix+=1
print(prefix)
