t = int(input())


def solve(prob_num):
    r, c = map(int, input().split())
    ru = "+" + "-+" * (c - 1)
    ru2 = "|" + ".|" * (c - 1)
    print(f"Case #{prob_num}:")

    print(".." + ru)
    print(".." + ru2)
    u = "+-" + ru
    u2 = "|." + ru2
    print(u)
    for _ in range(r - 1):
        print(u2)
        print(u)


for i in range(t):
    solve(i + 1)
