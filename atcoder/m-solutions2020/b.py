a,b,c = map(int,input().split())
k = int(input())
while k:
    if a >= b:
        b*=2
    elif b >= c:
        c*=2
    k-=1

if a < b and b < c:
    print("Yes")
else:
    print("No")