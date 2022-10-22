a,b,c,d = map(int,input().split())
su = a+b+c+d
if su % 2:
    print("No")
    exit()
if su//2 in [a,b,c,d,a+b,a+c,a+d,b+c,b+d,c+d]:
    print("Yes")
    exit()
print("No")