n = int(input())
a = list(map(int,input().split()))
if 0 in a:
    print(0)
    exit()
ret = 1
for a_ in a:
    ret *= a_
    if ret > 10**18:
        print(-1)
        exit()
print(ret)