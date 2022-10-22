n = int(input())

lb = 1
ub = n
while lb < ub:
    mid = (lb+ub)//2
    if (2*n+3-mid)*mid//2 >= n*(n+1)//2:
        ub = mid
    else:
        lb = mid+1

print(lb)