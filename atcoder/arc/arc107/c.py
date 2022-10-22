n,k = map(int,input().split())
a = []
for _ in range(n):
    b = map(int,input().split())
    a.append(list(b))

movable_x_cnt = 0
for i in range(n):
    bl = False
    for j in range(n):
        if i != j and all([a[i][kk] + a[j][kk] <= k for kk in range(n)]):
            bl = True
    if bl:
        movable_x_cnt += 1

movable_y_cnt = 0
for i in range(n):
    bl = False
    for j in range(n):
        if i != j and all([a[kk][i] + a[kk][j] <= k for kk in range(n)]):
            bl = True
    if bl:
        movable_y_cnt += 1

mod = 998244353
def fact(x):
    if x == 0:
        return 1
    return x*fact(x-1)%mod

print((fact(movable_x_cnt)*fact(movable_y_cnt))%mod)