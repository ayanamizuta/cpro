from fractions import Fraction
n=int(input())
lr=[list(map(int,input().split())) for _ in range(n)]
table=[lr[0][0],lr[0][1],None,None,False]

print(0)
for i in range(1,n):
    l,r=lr[i]
    if table[2] is None:
        if table[0]>=r:
            table[2]=(Fraction(table[0],1)+Fraction(r,1))/2
            table[3]=(Fraction(table[0],1)-Fraction(r,1))/2
        elif table[1]<=l:
            table[2]=(Fraction(l,1)+Fraction(table[1],1))/2
            table[3]=(Fraction(l,1)-Fraction(table[1],1))/2
        else:
            table[0]=max(table[0],l)
            table[1]=min(table[1],r)
    else:
        if table[2]+table[3] < l:
            vx = table[2]-table[3]
            table[2]=(vx+l)/2
            table[3]=(l-vx)/2
        elif table[2]-table[3] > r:
            vx = table[2]+table[3]
            table[2]=(vx+r)/2
            table[3]=(vx-r)/2
    
    if table[2] is None:
        print(0)
    else:
        if table[2].denominator==2:
            print((table[3]+Fraction(1,2)).numerator)
        else:
            print(table[3].numerator)