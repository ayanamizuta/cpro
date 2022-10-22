n = int(input())
t = input()
if t == "1":
    print(2*10**10)
    exit()
elif t == "0":
    print(10**10)
    exit()
elif t == "11":
    print(10**10)
    exit()
elif t == "10":
    print(10**10)
    exit()
elif t == "01":
    print(10**10-1)
    exit()
elif t == "00":
    print(0)
    exit()

init = 0
if t[:3] == "110":
    init = 0
elif t[:3] == "101":
    init = 1
elif t[:3] == "011":
    init = 2
else:
    print(0)
    exit()
nn = len(t)
for i in range(nn):
    if t[i] != "110"[(init+i)%3]:
        print(0)
        exit()
print((3*10**10-nn-init)//3+1)