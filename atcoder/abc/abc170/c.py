x,n=map(int,input().split())
p = list(map(int,input().split()))

if not x in p:
    print(x)
    exit()
for i in range(1,200):
    if not x-i in p:
        print(x-i)
        exit()
    elif not x+i in p:
        print(x+i)
        exit()