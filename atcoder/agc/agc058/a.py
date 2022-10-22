n=int(input())
p=list(map(int,input().split()))
x=[0]*n
k=0
violate=[True]*(2*n-1)
for i in range(2*n-1):
    if i%2 and p[i]>p[i+1]:
        violate[i]=False
    elif i%2==0 and p[i]<p[i+1]:
        violate[i]=False
i=0
while i<2*n-1:
    if i==2*n-2 and violate[i]:
        x[k]=i
        k+=1
        break
    if violate[i] and violate[i+1]:
        if i%2:
            if p[i]<p[i+2]:
                x[k]=i
                k+=1
                p[i],p[i+1]=p[i+1],p[i]
                violate[i]=False
                violate[i+1]=False
            else:
                x[k]=i+1
                k+=1
                p[i+1],p[i+2]=p[i+2],p[i+1]
                violate[i]=False
                violate[i+1]=False
                if i+2<2*n-1 and p[i+2]>p[i+3]:
                    violate[i+2]=False
        else:
            if p[i]>p[i+2]:
                x[k]=i
                k+=1
                p[i],p[i+1]=p[i+1],p[i]
                violate[i]=False
                violate[i+1]=False
            else:
                x[k]=i+1
                k+=1
                p[i+1],p[i+2]=p[i+2],p[i+1]
                violate[i]=False
                violate[i+1]=False
                if i+2<2*n-1 and p[i+2]<p[i+3]:
                    violate[i+2]=False
    elif violate[i]:
        x[k]=i
        k+=1
        p[i],p[i+1]=p[i+1],p[i]
        violate[i]=False
    i+=1




print(k)
for i in range(n):
    x[i]+=1
if k:
    print(*x[:k])
