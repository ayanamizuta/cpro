n = int(input())
primes = []
t = 2
n_ = n
while t*t <= n_ and t*t < n:
    if n % t == 0:
        cnt = 1
        while n % (t ** (cnt+1)) == 0:
            cnt += 1
        primes.append([t,cnt])
        n //= (t**cnt)
    t += 1
if n != 1:
    primes.append([n,1])

def largest_tri(m):
    cnt = 0
    for i in range(1,m+3):
        cnt += i
        if cnt > m:
            return i - 1

ret = 0
for p in primes:
    ret += largest_tri(p[1])
print(ret)