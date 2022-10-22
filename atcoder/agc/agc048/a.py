t = int(input())
def solve(s):
    if s == "a"*len(s):
        print(-1)
        return
    if "atcoder" < s:
        print(0)
        return
    if len(s) == 1:
        print(-1)
        return
    idx = 1
    while True:
        if s[idx] != 'a':
            if s[idx] > 't':
                print(idx-1)
            else:
                print(idx)
            return
        idx+=1

for _ in range(t):
    s_ = input()
    solve(s_)