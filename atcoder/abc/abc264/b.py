r,c=map(int,input().split())
r-=8
c-=8
x=max(abs(r),abs(c))
print(["white","black"][x%2])