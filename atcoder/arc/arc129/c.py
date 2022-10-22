n=int(input())

def nc2(m):
    return m*(m-1)//2

def max_sq(x):
    lb=2
    ub=1500
    while lb<ub:
        mid=(lb+ub)//2
        if nc2(mid) < x:
            lb=mid+1
        else:
            ub=mid
    return lb

def decomp(x):
    idx=max_sq(x)
    if nc2(idx)==x:
        return [idx-1]
    elif nc2(idx)>x:
        idx-=1
    return [idx-1] + decomp(x-nc2(idx))

def moddiv(a,b):
    for i in range(1,7):
        if a == (b*i)%7:
            return i

arr = decomp(n)

if len(arr)==1:
    print("7"*arr[0])
elif len(arr)==2:
    print("7"*arr[0]+"1"+"7"*arr[1])
elif len(arr)==3:
    coef1=pow(10,arr[1]+1,7)
    d1 = moddiv(2,coef1)
    print("7"*arr[0]+str(d1)+"7"*arr[1]+"1"+"7"*arr[2])
elif len(arr)==4:
    coef1=pow(10,arr[2]+1,7)
    coef2=pow(10,arr[1]+1+arr[2]+1,7)
    d1 = moddiv(2,coef1)
    d2 = moddiv(3,coef2)
    print("7"*arr[0]+str(d2)+"7"*arr[1]+str(d1)+"7"*arr[2]+"1"+"7"*arr[3])
elif len(arr)==5:
    coef1=pow(10,arr[3]+1,7)
    coef2=pow(10,arr[2]+1+arr[3]+1,7)
    coef3=pow(10,arr[1]+1+arr[2]+1+arr[3]+1,7)
    d1 = moddiv(2,coef1)
    d2 = moddiv(3,coef2)
    d3 = moddiv(3,coef3)
    print("7"*arr[0]+str(d3)+"7"*arr[1]+str(d2)+"7"*arr[2]+str(d1)+"7"*arr[3]+"1"+"7"*arr[4])
else:
    coef1=pow(10,arr[4]+1,7)
    coef2=pow(10,arr[3]+1+arr[4]+1,7)
    coef3=pow(10,arr[2]+1+arr[3]+1+arr[4]+1,7)
    coef4=pow(10,arr[1]+1+arr[2]+1+arr[3]+1+arr[4]+1,7)
    d1 = moddiv(2,coef1)
    d2 = moddiv(3,coef2)
    d3 = moddiv(3,coef3)
    d4 = moddiv(2,coef4)
    print("7"*arr[0]+str(d4)+"7"*arr[1]+str(d3)+"7"*arr[2]+str(d2)+"7"*arr[3]+str(d1)+"7"*arr[4]+"1"+"7"*arr[5])