n=int(input())

arr = [[[0 for _ in range(101)] for _ in range(101)] for _ in range(101)]

def g(x,y,z):
    return x**2+y**2+z**2+x*y+x*z+y*z

table = [0]*10001

for i in range(1,101):
    for j in range(1,101):
        for k in range(1,101):
            re = g(i,j,k)
            if re <= 10000:
                table[re]+= 1



for i in range(1,n+1):
    print(table[i])