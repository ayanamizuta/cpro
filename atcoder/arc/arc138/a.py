from bisect import bisect_left
n, k = map(int, input().split())
a = list(map(int, input().split()))
a_right = []

for i in range(k, n):
    a_ = a[i]
    if (not a_right) or a_right[-1][0] < a_:
        a_right.append([a_, i])


ret = 10**10
for i in range(k):
    idx_ = bisect_left(a_right, [a[i], 10**10])
    if idx_ == len(a_right):
        continue
    idx = a_right[idx_][1]
    #print(i, idx, a[i])
    ret = min(ret, idx - i)

if ret == 10**10:
    print(-1)
else:
    print(ret)
