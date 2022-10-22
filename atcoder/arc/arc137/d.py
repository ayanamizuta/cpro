#n, m = map(int, input().split())
#a = list(map(int, input().split()))

from random import randint
n, m = 1000000, 1000000
a = [randint(0, 10000000) for _ in range(n)]

memo = []
memo.append(a)


def all_same(l1, l2):
    for l1_, l2_ in zip(l1, l2):
        if l1_ != l2_:
            return False
    return True


b = [a_ for a_ in a]
for i in range(m):
    b_next = [b[0]] + [0] * (n - 1)
    for j in range(n - 1):
        b_next[j + 1] = b_next[j] ^ b[j + 1]
    if all_same(a, b_next):
        break
    memo.append([b_ for b_ in b_next])
    b = b_next
    print(i)

ret = [0] * m
for i in range(1, m + 1):
    ret[i - 1] = memo[i % len(memo)][-1]
# print(memo)
print(*ret)
