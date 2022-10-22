from itertools import product
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
"""for i in range(n):
    for j in range(n - 2):
        while a[j] != min(a[j:j + 3]) or a[j + 1] != min(a[j:j + 2]):
            a[j], a[j + 1], a[j + 2] = a[j + 1], a[j + 2], a[j]

for i in range(n):
    for j in range(n - 2):
        while b[j] != min(b[j:j + 3]) or b[j + 1] != min(b[j:j + 2]):
            b[j], b[j + 1], b[j + 2] = b[j + 1], b[j + 2], b[j]"""

for i, j in product(range(n), range(n - 2)):
    m=min(a[j:j + 3])
    while a[j] != m or a[j + 1] != min(a[j+1:j + 3]):
        a[j], a[j + 1], a[j + 2] = a[j + 1], a[j + 2], a[j]

for i, j in product(range(n), range(n - 2)):
    m=min(b[j:j + 3])
    while b[j] != m or b[j + 1] != min(b[j+1:j + 3]):
        b[j], b[j + 1], b[j + 2] = b[j + 1], b[j + 2], b[j]

for i in range(n):
    if a[i] != b[i]:
        print("No")
        exit()
print("Yes")
