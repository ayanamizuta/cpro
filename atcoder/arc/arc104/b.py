n,s = input().split()
n = int(n)
a = [[0 for _ in range(n)] for _ in range(n)]
t = [[0 for _ in range(n)] for _ in range(n)]
c = [[0 for _ in range(n)] for _ in range(n)]
g = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    if s[i] == 'A':
        a[i][i] = 1
    elif s[i] == 'T':
        t[i][i] = 1
    elif s[i] == 'C':
        c[i][i] = 1
    else:
        g[i][i] = 1
    for j in range(i+1,n):
        a[i][j] = a[i][j-1]
        t[i][j] = t[i][j-1]
        c[i][j] = c[i][j-1]
        g[i][j] = g[i][j-1]
        if s[j] == 'A':
            a[i][j] = a[i][j-1]+1
        elif s[j] == 'T':
            t[i][j] = t[i][j-1]+1
        elif s[j] == 'C':
            c[i][j] = c[i][j-1]+1
        elif s[j] == 'G':
            g[i][j] = g[i][j-1]+1

cnt = 0
#print(a,g,c,t)
for i in range(n):
    for j in range(i+1,n):
        if a[i][j] == t[i][j] and c[i][j] == g[i][j]:
            #print(i,j)
            cnt+=1
print(cnt)