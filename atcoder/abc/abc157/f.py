n,kk = map(int,input().split())
x = [0]*n
y = [0]*n
c = [0]*n

for i in range(n):
    x[i],y[i],c[i] = map(int,input().split())

from math import sqrt
import sympy.geometry as sg
def ok(t):
    cand = [[x[i],y[i]] for i in range(n)]
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            
            result = sg.intersection(sg.Circle(sg.Point(x[i],y[i]), t/c[i]*(1.000001)),sg.Circle(sg.Point(x[j],y[j]), t/c[j]*(1.000001)))
            for res in result:
                cand.append([res.x,res.y])

    for x_,y_ in cand:
        cnt = 0
        for k in range(n):
            if (x_-x[k])**2 + (y_-y[k])**2 < (t/c[k])**2*(1.000001):
                cnt += 1
            if cnt >= kk:
                return True

    return False



lb = 0
ub = 100*2000
while (ub - lb)/ub > 0.00000001:
    mid = (lb+ub)/2
    if ok(mid):
        ub = mid
    else:
        lb = mid

print(mid)