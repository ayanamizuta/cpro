n,m = map(int,input().split())
odd=0
even=0
for _ in range(n):
    s = input()
    cnt = s.count("1")
    if cnt%2:
        odd+=1
    else:
        even+=1
print(odd*even)