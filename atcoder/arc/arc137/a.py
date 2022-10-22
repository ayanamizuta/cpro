from math import gcd
l, r = map(int, input().split())
x = r - l

for d in range(x, 0, -1):
    for l_ in range(l, r - d + 1):
        if gcd(l_, l_ + d) == 1:
            print(d)
            exit()
