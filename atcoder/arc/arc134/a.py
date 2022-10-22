n, l, w = map(int, input().split())
a = list(map(int, input().split()))

ret = 0
ptr = 0
for a_ in a:
    if ptr >= a_:
        ptr = a_ + w
        continue
    ret += (a_ - ptr + w - 1) // w
    ptr = a_ + w
if ptr < l:
    ret += (l - ptr + w - 1) // w

print(ret)
