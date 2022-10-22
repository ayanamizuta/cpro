
def max_chain(n):
    if n==1:
        return 1
    ret=1
    for i in range(2,n):
        if (n-1)%i==0:
            ret=max(ret,1+max_chain((n-1)//i))
        elif (n-1)//i<1:
            break
    return ret

def solve(pn):
    n=int(input())
    ret=1
    for i in range(3,n):
        if n%i==0:
            ret=max(ret,max_chain(n//i))
        elif (n-1)//i<2:
            break

    print(f"Case #{pn}: {ret}")

t=int(input())
for i in range(t):
    solve(i+1)