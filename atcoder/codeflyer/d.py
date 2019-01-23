n=int(input())
a=[[0]*60 for i in range(n)]
b=[[0]*60 for i in range(n)]

c=list(map(int,input().split()))
for i in range(n):
    for j in range(60):
        a[i][j]=c[i]%2
        c[i]//=2

c=list(map(int,input().split()))
for i in range(n):
    for j in range(60):
        b[i][j]=c[i]%2
        c[i]//=2

def xor(a,b):
    return [a[i]^b[i] for i in range(len(a))]
        
def st(a):
    piv=0
    for i in range(60):
        bl_rank=False
        for j in range(piv,n):
            if a[j][i]:
                a[piv],a[j]=a[j],a[piv]
                bl_rank=True
                break
        if bl_rank:
            for j in range(n):
                if piv!=j and a[j][i]:
                    a[j] = xor(a[j],a[piv])
            piv+=1
    return a

c=st(a)
d=st(b)

if c==d:
    print("Yes")
else:
    print("No")
