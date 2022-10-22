t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    if n % 2 == 0:
        bl = True
        for i in range(n//2):
            if a[2*i] != a[2*i+1]:
                bl = False
                break
        if bl:
            print("Second")
            continue
        else:
            print("First")
            continue
    else:
        print("Second")