n = int(input())
s_ = input()
s = "".join([str(int(x)-1) for x in s_])

def pascal(m):
    b = 2
    while m > b:
        b *= 2
    if m == b:
        return [1]*m
    
    return arr

def solve(s):
    arr = pascal(len(s))
    su = 0
    for i,x in enumerate(arr):
        if x:
            su += int(s[i])
            su %= 2
    return su

if "1" not in s:
    s2 = "".join([str(int(x)//2) for x in s])
    print(2*solve(s2))
else:
    print(solve(s))