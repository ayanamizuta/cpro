from fractions import Fraction

def floor_sum(n, m, a, b):
    ans = 0
    if a >= m:
        ans += (n - 1) * n * (a // m) // 2
        a %= m
    if b >= m:
        ans += n * (b // m)
        b %= m
 
    y_max = (a * n + b) // m
    x_max = y_max * m - b
    if y_max == 0:
        return ans
    ans += (n - (x_max + a - 1) // a) * y_max
    ans += floor_sum(y_max, a, m, (a - x_max) % a)
    return ans

def c_min(frac1,frac2):
    if frac2 is None:
        return [frac1.numerator//frac1.denominator+1,1]
    if frac1 is None:
        return [1,frac2.denominator//frac2.numerator+1]
    # j*fn1 < fd1*c , c*fd2 < fn2*j
    fn1=frac1.numerator
    fd1=frac1.denominator
    fn2=frac2.numerator
    fd2=frac2.denominator
    def ok(mid):
        return floor_sum(mid,fd1*fd2,fn1*fd2,fd1*fd2-1) == floor_sum(mid,fd1*fd2,fd1*fn2,fd1*fd2-1)
    lb=1
    ub=fn1*fn2*fd1*fd2
    while lb<ub:
        mid=(lb+ub)//2
        if ok(mid):
            lb=mid+1
        else:
            ub=mid
    
    c=lb-1
    j=c*fd2//fn2+1
    return [c,j]



def solve(pn):
    n=int(input())
    c = [list(map(int,input().split())) for _ in range(n)]
    slopes = set([])
    for i in range(n):
        for j in range(i+1,n):
            if (c[i][0]-c[j][0])*(c[i][1]-c[j][1])<0:
                slopes.add(Fraction(c[i][0]-c[j][0],c[i][1]-c[j][1]))

    if not len(slopes) and c == sorted(c,key=lambda x:x[0]+x[1]):
        print(f"Case #{pn}: 1 1")
        return

    
    sorted_slopes = sorted(list(slopes))
    for i,slope in enumerate(sorted_slopes):
        if not i:
            c_, j_ = c_min(-slope,None)
            if c == sorted(c,key=lambda x:x[0]*c_+x[1]*j_):
                print(f"Case #{pn}: {c_} {j_}")
                return
        if i==len(sorted_slopes)-1:
            c_, j_ = c_min(None,-slope)
            if c == sorted(c,key=lambda x:x[0]*c_+x[1]*j_):
                print(f"Case #{pn}: {c_} {j_}")
                return
        if i<len(sorted_slopes)-1:
            c_, j_ = c_min(-sorted_slopes[i+1],-slope)
            if c == sorted(c,key=lambda x:x[0]*c_+x[1]*j_):
                print(f"Case #{pn}: {c_} {j_}")
                return

    print(f"Case #{pn}: IMPOSSIBLE")

t=int(input())
for i in range(t):
    solve(i+1)