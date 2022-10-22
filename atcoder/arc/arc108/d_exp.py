n = int(input())
arr = []
ss = "AB"

def dfs(s):
    if len(s) == n:
        arr.append(s)
        return
    for i in range(len(s)-1):
        if s[i:i+2] == "AA":
            dfs(s[:i+1]+c[0]+s[i+1:])
        elif s[i:i+2] == "AB":
            dfs(s[:i+1]+c[1]+s[i+1:])
        elif s[i:i+2] == "BA":
            dfs(s[:i+1]+c[2]+s[i+1:])
        elif s[i:i+2] == "BB":
            dfs(s[:i+1]+c[3]+s[i+1:])

c_in=["A","B"]
for c1 in c_in:
    for c2 in c_in:
        for c3 in c_in:
            for c4 in c_in:
                c=[c1,c2,c3,c4]
                dfs(ss)
                print(c,len(set(arr)))
                arr=[]
