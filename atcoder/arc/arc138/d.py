n, k = map(int, input().split())
if k % 2 == 0:
    print("No")
    exit()
if n == k:
    print("No")
    exit()


def popcnt(n):
    c = 0
    for i in range(64):
        c += (n >> i) & 1
    return c


template_3 = [0, 1, 3, 2, 6, 7, 5, 4]

template = [t for t in template_3]
for d in range(3, n):
    idx = 0
    last = template[-1]
    if d > k:
        for idx_ in range(len(template)):
            if popcnt(last ^ template[idx_]) == k - 1:
                idx = idx_
                break
        template = template + [(1 << d) + t for t in template[idx:]] + \
            [(1 << d) + t for t in template[:idx]]
    else:
        template = template + [(1 << d) + t for t in template[::-1]] 
    if d == k:
        for i in range(len(template)):
            if i % 2 == 1:
                template[i] = (1 << (d + 1)) - 1 - template[i]
print("Yes")
print(*template)
