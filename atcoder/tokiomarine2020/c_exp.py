n = 200000
a = [0]*n
a_next = [0]*n
for i in range(n):
    a_next = [0]*n
    for j in range(n):
        for k in range(max(0,j-a[j]),min(n-1,j+a[j])+1):
            a_next[k] += 1
    for j in range(n):
        a[j] = a_next[j]
    del a_next
    print(i,a[0])