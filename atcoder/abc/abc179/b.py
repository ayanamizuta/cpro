n = int(input())
acm = 0
for _ in range(n):
    d1,d2 = input().split()
    if d1 == d2:
        acm+=1
    else:
        acm = 0
    if acm == 3:
        print("Yes")
        exit()
print("No")