from itertools import product
n,m=map(int,input().split())

res = list(range(1,10))

ret_arr=[0,0]

for k in range(1,n+1):
    for i in range(1,10):
        #print(k,i,res[i-1],ret_arr)
        if res[i-1]%m==0:
            ret_arr=max(ret_arr,[k,i])
        res[i-1]=(10*res[i-1]+i)%m
        

if ret_arr==[0,0]:
    print(-1)
else:
    print(str(ret_arr[1])*ret_arr[0])