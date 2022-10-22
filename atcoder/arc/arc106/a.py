n = int(input())
for i in range(1,37):
    nn = n
    nn -= (5**i)
    if nn <= 0:
        continue
    for j in range(1,55):
        if nn == 3**j:
            print(j,i)
            exit()

print(-1)