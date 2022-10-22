s,n = map(int,input().split())

p = 1
while p*p < n + 4:
    if n % p == 0 and p + n//p == s:
        print("Yes")
        exit()
    p+=1
print("No")