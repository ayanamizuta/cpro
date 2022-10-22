def gcd(a,b):
    if a < b:
        return gcd(b,a)
    if b == 0:
        return a
    return gcd(b,a%b)

n = int(input())
a = list(map(int,input().split()))
ret = a[0]
for i in range(1,n):
    ret = gcd(ret,a[i])
print(ret)