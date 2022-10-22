k = int(input())
ret = 0
table = [0]*(k+1)
for i in range(1,k+1):
    for j in range(1,k+1):
        if i*j>k:
            break
        table[i*j] += 1

table_sum = [0]*(k+1)
for i in range(1,k+1):
    table_sum[i] = table[i]+table_sum[i-1]

for i in range(1,k+1):
    d = k//i
    ret += table_sum[d]
print(ret)