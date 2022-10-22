from collections import Counter
n = int(input())
s_arr = list(input())

cnt = Counter()
for c in s_arr:
    cnt[c] += 1


def get_lowest(cnt):
    for i in range(26):
        if cnt[chr(ord("a") + i)]:
            return chr(ord("a") + i)


maxi = n - 1
for i in range(n):
    if i >= maxi:
        break
    lowest = get_lowest(cnt)
    if s_arr[i] == lowest:
        cnt[s_arr[i]] -= 1
        continue
    while s_arr[maxi] != lowest:
        cnt[s_arr[maxi]] -= 1
        maxi -= 1
        if i >= maxi:
            break
    if i < maxi and s_arr[maxi] == lowest:
        s_arr[i], s_arr[maxi] = s_arr[maxi], s_arr[i]
        cnt[s_arr[maxi]] -= 1
        maxi -= 1
    cnt[s_arr[i]] -= 1

print("".join(s_arr))
