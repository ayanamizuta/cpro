import numpy as np
n = int(input())
a = list(map(int, input().split()))
np_a = np.array(a)
ind = np.argsort(np_a)[n // 2:]
# print(ind)
table = [0] * n

for i in ind:
    table[i] = 1

sum_table = [0] * (n // 2 + 1)
for i in range(n // 2):
    sum_table[i + 1] = sum_table[i] + (table[2 * i] + table[2 * i + 1] - 1)
# print(sum_table)
maxi = 0
max_value = 0
for i in range(n // 2):
    if max_value < sum_table[i + 1]:
        max_value = sum_table[i + 1]
        maxi = 2 * i

if maxi + 2 < n:
    print(maxi + 2, sum(np_a[i] for i in ind))
else:
    print(0, sum(np_a[i] for i in ind))
