n=int(input())
if n==3:
    print("6 2 4")
    print("9 7 8")
    print("3 5 1")
    exit()
if n==4:
    print("15 11 16 12")
    print("13 3 6 9")
    print("14 7 8 1")
    print("4 2 10 5")
    exit()

arr = [[0 for _ in range(n)] for _ in range(n)]

evens = []
for i in range(1,n*n+1):
    if i%2==0 and i%3!=0:
        evens.append(i)
for i in range(1,n*n+1):
    if i%2==0 and i%3==0:
        evens.append(i)

odds = []
for i in range(1,n*n+1):
    if i%2!=0 and i%3==0:
        evens.append(i)
for i in range(1,n*n+1):
    if i%2!=0 and i%3!=0:
        evens.append(i)

idx=0
for i in range(n):
    for j in range(n):
        arr[i][j]=evens[idx] if idx<len(evens) else odds[idx-len(evens)]
        idx+=1
    
for i in range(n):
    print(*arr[i])
