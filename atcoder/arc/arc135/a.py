x = int(input())
mod = 998244353

cache = {}


def solve(n):
    if n <= 4:
        return n
    n2 = n // 2
    if n2 == (n - n2):
        if cache.get(n2) is not None:
            s = cache[n2]
        else:
            s = solve(n2)
            cache[n2] = s % mod
        return s * s % mod
    if cache.get(n2) is not None:
        s = cache[n2]
    else:
        s = solve(n2)
        cache[n2] = s % mod
    if cache.get(n - n2) is not None:
        s_ = cache[n - n2]
    else:
        s_ = solve(n - n2)
        cache[n - n2] = s_ % mod
    return s * s_ % mod


print(solve(x))
