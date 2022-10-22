a,b,x,y = map(int,input().split())
if a > b:
    ret = x + y*(a-b-1)
    ret = min(ret,x*(1+(a-b-1)*2))
    print(ret)
else:
    ret = x*(1+(b-a)*2)
    ret = min(ret,x+y*(b-a))
    print(ret)