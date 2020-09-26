n = int(input())
s = input()

su = s.count('1')
sun = int(s,2)

sun_plus = sun % (su + 1)
sun_minus = 0 if su - 1 == 0 else sun % (su - 1)


table = [0]*200001
table[1] = 1
for i in range(2,200001):
    table[i] = 1 + table[i % bin(i).count('1')]

def pow(n,e,mod):
    ret=1
    b=n
    while e > 0:
        if e % 2 == 1:
            ret = ret * b % mod
        b = b * b % mod
        e = e//2
    return ret

for i in range(n):
    if s[i] == '0':
        print(1+table[(sun_plus+pow(2,n-1-i,su+1))%(su+1)])
    else:
        if su-1 == 0:
            print(0)
        else:
            print(1+table[(sun_minus-pow(2,n-1-i,su-1)+su-1)%(su-1)])
