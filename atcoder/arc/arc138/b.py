n = int(input())
a = list(map(int, input().split()))

flip = 0
front = 0
end = n - 1

while front != end:
    if a[end] ^ flip:
        if a[front] ^ flip:
            print("No")
            exit()
        front += 1
        flip = 0 if flip else 1
    else:
        end -= 1

if a[front] ^ flip:
    print("No")
else:
    print("Yes")
