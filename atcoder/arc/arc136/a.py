n = int(input())
s = input()
s_arr = list(s)
s_after = []

for idx in range(n):
    if not idx:
        s_after.append(s_arr[idx])
        continue
    if s_after[-1] == "B" and s_arr[idx] == "A":
        s_after[-1] = "A"
        s_after.append("B")
    elif s_after[-1] == "B" and s_arr[idx] == "B":
        s_after[-1] = "A"
    else:
        s_after.append(s_arr[idx])

print("".join(s_after))
