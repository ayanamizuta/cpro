n = int(input())
a = list(map(int, input().split()))

d = None
for i in range(n - 1):
    if a[i] > a[i + 1]:
        d = a[i]
        break

if d is None:
    d = a[-1]

print(*list(filter(lambda x: x != d, a)))
