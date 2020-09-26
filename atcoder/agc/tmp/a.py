h,w = map(int,input().split())
s = [input() for _ in range(h)]

dp = [[0 for _ in range(w)] for _ in range(h)]

for i in range(h):
    for j in range(w-1):
        if i > 0:
            dp[i][0] = dp[i-1][0] if s[i][0] == s[i-1][0] else dp[i-1][0]+1
            above = dp[i-1][j+1]
            left  = dp[i][j]
            if s[i-1][j+1] != s[i][j+1]:
                above += 1
            if s[i][j] != s[i][j+1]:
                left += 1
            dp[i][j+1] = min(above,left)
        else:
            left  = dp[i][j]
            if s[i][j] != s[i][j+1]:
                left += 1
            dp[i][j+1] = left

n = dp[-1][-1]
if s[0][0] == '.' and s[-1][-1] == '.':
    print(n//2)
elif s[0][0] == '#' and s[-1][-1] == '#':
    print(n//2+1)
else:
    print((n+1)//2)