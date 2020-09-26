l,a,b,m=map(int,input().split())

def pow(e,p):
    b = e
    ret = 1
    while p > 0:
        if p % 2:
            ret *= b
            ret %= m
        b = b * b
        b %= m
        p //= 2
    return ret

def powow(n,p):
    b = n
    ret = 1
    while p > 0:
        if p % 2:
            ret *= b
        b = b * b
        p //= 2
    return ret

def sol(be,en,le,po):
    ll = len(str(be))
    ret = (en*(powow(10,ll*le)-1)//(10**ll-1))%m
    minus = b*((10**ll-powow(10,ll*le)-(le-1)*(powow(10,ll*le))+(le-1)*(powow(10,ll*(le+1))))//(10**ll-1)//(10**ll-1)) % m
    ret = ret + m - minus
    return ret * po % m

def last(be):
    ub = 1
    while ub <= be:
        ub *= 10
    ubb = be + (ub-be-1)//b*b

    return [be,min(ubb,a+b*(l-1)),min((ubb-be)//b+1,(a+b*(l-1)-be)//b+1)]

arr = []
be = a
while (be - a)//b < l:
    arr = [last(be)] + arr
    be = arr[0][1] + b


ret = 0
po = 1
for a in arr:
    ret += sol(a[0],a[1],a[2],po)
    po *= pow(10,(len(str(a[0]))*a[2]))
    po %= m
    ret %= m
print(ret)