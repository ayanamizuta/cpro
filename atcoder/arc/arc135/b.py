n = int(input())
s = list(map(int, input().split()))

table = [0] * (n + 2)
for i in range(n - 1):
    table[i + 3] = table[i] + (s[i + 1] - s[i])

mi = 10**10
mi = min([table[i] for i in range(0, n + 2, 3)])
if mi < 0:
    for i in range(0, n + 2, 3):
        table[i] -= mi

mi = min([table[i] for i in range(1, n + 2, 3)])
if mi < 0:
    for i in range(1, n + 2, 3):
        table[i] -= mi

mi = min([table[i] for i in range(2, n + 2, 3)])
if mi < 0:
    for i in range(2, n + 2, 3):
        table[i] -= mi

if sum(table[:3]) > s[0]:
    print("No")
    exit()
p = s[0] - sum(table[:3])
for i in range(0, n + 2, 3):
    table[i] += p

print("Yes")
print(*table)
