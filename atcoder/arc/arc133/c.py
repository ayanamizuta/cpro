h, w, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

if sum(a) % k != sum(b) % k:
    print(-1)
    exit(0)


def max_feasible(m, len_opposite):
    return ((k - 1) * len_opposite) // k * k + m if ((k - 1) *
                                                     len_opposite) % k >= m else ((k - 1) * len_opposite) // k * k - k + m


a_max = [max_feasible(a_, w) for a_ in a]
b_max = [max_feasible(b_, h) for b_ in b]

print(min(sum(a_max), sum(b_max)))
