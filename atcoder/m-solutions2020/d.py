n = int(input())
a = list(map(int,input().split()))

tmp = 0
a_filter = []
idx = 0
while idx < len(a) - 1:
    if a[idx] < a[idx+1]:
        a_filter += [a[idx],a[idx+1]]
    idx+=1

ret = 1000
tmp = 0
for i,x in enumerate(a_filter):
    if i % 2:
        ret += tmp*x
    else:
        tmp = ret // x
        ret -= tmp * x
print(ret)