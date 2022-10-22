n = int(input())
a = list(map(int, input().split()))

suma = [0] * 30
for b in range(30):
    for i in range(n):
        suma[b] += 1 if a[i] & (1 << b) else 0

maxi = 0
for i in range(n):
    maxi_cand = 0
    for b in range(30):
        if a[i] & (1 << b):
            maxi_cand += (1 << b) * (n - 2 * suma[b])
    maxi = max(maxi, maxi_cand)

print(sum(a) + maxi)
