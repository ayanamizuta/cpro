n = int(input())
a_ = [0]*n
b_ = [0]*n
c = [0]*n
for i in range(n):
    a_[i],b_[i] = map(int,input().split())
    c[i] = a_[i]
lb_ = 1
ub_ = 10**9
c.sort()
med = c[(n-1)//2]
med_ub = c[(n-1)//2+1]


def ok_odd(m):
    cnt = 0
    for i in range(n):
        a = a_[i]
        if a <= m:
            cnt += 1
    if cnt < (n+1)//2:
        return False
    cnt = 0
    for i in range(n):
        b = b_[i]
        if b >= m:
            cnt += 1
    if cnt < (n+1)//2:
        return False
    cnt = 0
    for i in range(n):
        a,b = a_[i],b_[i]
        if a <= m and m <= b:
            return True
    return False

def ok_even_lb(m):
    cnt = 0
    for i in range(n):
        a = a_[i]
        if a <= m:
            cnt += 1
    if cnt < n//2:
        return False
    cnt = 0
    for i in range(n):
        b = b_[i]
        if b >= m:
            cnt += 1
    if cnt < n//2 + 1:
        return False
    cnt = 0
    for i in range(n):
        a,b = a_[i],b_[i]
        if a <= m and m <= b:
            return True
    return False

def ok_even_ub(m):
    cnt = 0
    for i in range(n):
        a = a_[i]
        if a <= m:
            cnt += 1
    if cnt < n//2 + 1:
        return False
    cnt = 0
    for i in range(n):
        b = b_[i]
        if b >= m:
            cnt += 1
    if cnt < n//2:
        return False
    cnt = 0
    for i in range(n):
        a,b = a_[i],b_[i]
        if a <= m and m <= b:
            return True
    return False

if n % 2 == 1:
    lb = 1
    ub = med
    while lb < ub:
        mid = (lb+ub)//2
        if ok_odd(mid):
            ub = mid
        else:
            lb = mid+1
    lb_ret = lb
    lb = med
    ub = 10**9
    while lb < ub:
        mid = (lb+ub+1)//2
        if ok_odd(mid):
            lb = mid
        else:
            ub = mid-1
    ub_ret = lb
    print(ub_ret-lb_ret+1)
else:
    lb = 1
    ub = med
    while lb < ub:
        mid = (lb+ub)//2
        if ok_even_lb(mid):
            ub = mid
        else:
            lb = mid+1
    lb_lb = lb
    lb = med
    ub = 10**9
    while lb < ub:
        mid = (lb+ub+1)//2
        if ok_even_lb(mid):
            lb = mid
        else:
            ub = mid-1
    lb_ub = lb

    lb = 1
    ub = med_ub
    while lb < ub:
        mid = (lb+ub)//2
        if ok_even_ub(mid):
            ub = mid
        else:
            lb = mid+1
    ub_lb = lb
    lb = med_ub
    ub = 10**9
    while lb < ub:
        mid = (lb+ub+1)//2
        if ok_even_ub(mid):
            lb = mid
        else:
            ub = mid-1
    ub_ub = lb
    print(ub_ub+lb_ub-lb_lb-ub_lb+1)