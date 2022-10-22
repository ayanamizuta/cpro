l=list(map(int,input().split()))

l.sort()
a,b,c=l
p=a+b
q=c
n=p-q
if n<0:
    print(-1)
    exit()
print(c)
