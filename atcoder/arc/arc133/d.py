l, r, v = map(int, input().split())


def sum_xor(x):
    if x % 4 == 0:
        return x
    if x % 4 == 1:
        return 1
    if x % 4 == 2:
        return x + 1
    return 0


def ok(l, r, v):
    return sum_xor(l - 1) ^ sum_xor(r) == v


def solve(l, r, v):
    ret = 0

    if r - l < 9:
        for l_ in range(l, r + 1):
            for r_ in range(l_, r + 1):
                m = 0
                for x in range(l_, r_ + 1):
                    m ^= x
                if m == v:
                    ret += 1

        return ret

    l_trim = l - 1
    r_trim = r

    while l_trim % 4 == 0:
        l_trim += 1
    while r_trim % 4 == 0:
        r_trim -= 1

    if v % 4 in [0, 3]:
        ret += solve(l_trim // 4, r_trim // 4, v // 4)
    if v == 3:
        ret += (r_trim - l_trim) // 4
    if v == 0:
        ret += (r_trim - l_trim) // 4

    zeros = ones = (r_trim - l_trim) // 4

    for i in range(l - 1, l_trim):
        m = 0
        for i_ in range(i, l_trim)

    if v_lower == 0:
        ret +=
