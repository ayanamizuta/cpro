import math

n,m=map(int,input().split())
mod = 1000000007

if m==1:
    print(1)
    exit()

dic = {}
p = 2
while True:
    if m==1:
        break
    if p > math.floor(math.sqrt(m))+1:
        if dic.get(m) is None:
            dic[m] = 1
        else:
            dic[m] += 1
        break
    if m % p == 0:
        if dic.get(p) is None:
            dic[p] = 1
        else:
            dic[p] += 1
        m = m//p
        p=1
    p+=1

def pow(n,e):
    ret=1
    b=n
    while e > 0:
        if e % 2 == 1:
            ret = ret * b % mod
        b = b * b % mod
        e = e//2
    return ret
    
def inv(n):
    return pow(n,mod-2)

def nck(n,k):
    ret = 1
    for i in range(1,k+1):
        ret *= (n-i+1) % mod
        ret %= mod
        ret *= inv(i) % mod
        ret %= mod
    return ret
    
ret=1
for x in dic.keys():
    ret = (ret * nck(n+dic[x]-1,min(n-1,dic[x]))) % mod

print(ret)
