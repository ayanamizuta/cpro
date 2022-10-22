n = int(input())
a = list(map(int, input().split()))
calc = [0] * (n + 1)
for i, a_ in enumerate(a):
    if a_ == 1:
        calc[i + 1] = calc[i] + 1
    else:
        calc[i + 1] = calc[i] - 1

maxin = 0
mini = 0

minin = 0
maxi = 0
for c in calc:
    mini = min(c, mini)
    maxin = max(maxin, c - mini)

    maxi = max(c, maxi)
    minin = max(minin, maxi - c)


print(1 + minin + maxin)
