n,k=map(int,input().split())

if n<k*2:
    print(-1)
    exit()
table = [True]*n
lb_=[0]

def update(lb_value):
    #print(lb_value,lb_[0])
    table[lb_value-1]=False
    if lb_[0]==lb_value-1:
        for i in range(lb_[0]+1,n):
            if table[i]:
                lb_[0]=i
                break
ret=[0]*n
for i in range(n):
    number=i+1
    lb=lb_[0]+1
    if i and ret[i-1]==n:
        for j in range(n-i):
            ret[i+j]=lb_[0]+1
            update(lb_[0]+1)
        break
    elif abs(lb-number)>=k:
        m=n-i-1
        if m-k>=k or m==0:
            ret[i]=lb
            update(lb)
        else:
            ret[i]=number+k
            update(number+k)
    else:
        ret[i]=number+k
        update(number+k)

print(*ret)
