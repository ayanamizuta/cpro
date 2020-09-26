n,m = map(int,input().split())

for i in range(2**n-1):
    if i % 2 == 0:
        print("1"*(2**m-1))
    else:
        print("10"*(2**(m-1)-1)+"1")