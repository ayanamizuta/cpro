k,a,b=map(int,input().split())
if a+2>=b or 1+k<=a:
    print(1+k)
    exit()
k-=a-1
print(a+(k%2)+(k//2)*(b-a))
