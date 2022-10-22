import sys
n = int(input())
a = list(map(int, input().split()))
a_mark = [False] * n
a_front_with_index = [(a[idx], idx) for idx in range(n)]

a_front_with_index.sort(key=lambda x: (x[0], x[1]))

first_ptr = 0
l = a_front_with_index[0][0]
for i in range(1, n):
    if a_front_with_index[i][0] == l:
        first_ptr = i
    else:
        break

if first_ptr == 0:
    a_mark[a_front_with_index[0][1]] = True
else:
    minv = min(a[n + a_front_with_index[idx][1]]
               for idx in range(first_ptr + 1))
    if minv > l:
        for idx in range(first_ptr + 1):
            a_mark[a_front_with_index[idx][1]] = True
    else:
        print(f"{l} {minv}")
        exit()

first_last_original_ptr = a_front_with_index[first_ptr][1]

first_back_val = a[n + a_front_with_index[0][1]]
curr_original_ptr = first_last_original_ptr
flag = False
for i in range(a_front_with_index[0][1] + 1, n):
    if a_mark[i] and a[i + n] > first_back_val:
        flag = True
        break
    if a_mark[i] and a[i + n] < first_back_val:
        break
for i in range(first_ptr + 1, n):
    if a_front_with_index[i][1] > curr_original_ptr and a_front_with_index[i][0] < first_back_val:
        a_mark[a_front_with_index[i][1]] = True
        curr_original_ptr = a_front_with_index[i][1]
    elif a_front_with_index[i][1] > curr_original_ptr and a_front_with_index[i][0] == first_back_val:
        if flag:
            a_mark[a_front_with_index[i][1]] = True
            curr_original_ptr = a_front_with_index[i][1]

for i in range(n):
    if a_mark[i]:
        sys.stdout.write(f"{a[i]} ")
for i in range(n):
    if a_mark[i]:
        sys.stdout.write(f"{a[i+n]} ")
print()
