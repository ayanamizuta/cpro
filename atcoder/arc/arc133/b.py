n = int(input())
p = list(map(int, input().split()))
q = list(map(int, input().split()))
rev_q = [0] * n
for i, q_ in enumerate(q):
    rev_q[q_ - 1] = i
table = [0] * n
table_max = [0] * n

for x in p:
    for div in range(x, n + 1, x):
        idx_q = rev_q[div - 1]
        if idx_q:
            table[idx_q] = max(table[idx_q], table[idx_q - 1] + 1)
        else:
            table[idx_q] = 1
    print(table)

print(max(table))
