n,m= map(int,input().split())
if n == 1 and m == 0:
    print(0)
    exit()
d = {}
for _ in range(m):
    s,c = map(int,input().split())
    if d.get(s) != None and d[s] != c:
        print(-1)
        exit()
    d[s] = c

ret = 0
for k in range(1,n+1):
    if k == 1 and d.get(k) == None:
        ret = 1
    elif k == 1:
        ret = d[k]
    elif d.get(k) == None:
        ret = 10*ret
    else:
        ret = 10*ret + d[k]
if len(str(ret)) != n:
    print(-1)
    exit()
print(ret)
