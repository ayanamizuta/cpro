
def p_(l):
    if l==0:
        return 1;
    return 1+2*p_(l-1)
def len_(l):
    if l==0:
        return 1;
    return 3+2*len_(l-1)
def solve(l,s):
    if s==0:
        return 0
    if s==le[l]:
        return p[l]
    elif s>=2+le[l-1]:
        return 1+p[l-1]+solve(l-1,s-2-le[l-1])
    elif s>=1+le[l-1]:
        return p[l-1]+solve(l-1,s-2-le[l-1])
    elif s>=2:
        return solve(l-1,s-1)
    return 0

n,x=map(int,input().split())
p=[0]*(n+1)
le=[0]*(n+1)
for i in range(n+1):
    p[i]=p_(i)
    le[i]=len_(i)
print(solve(n,x))
    
