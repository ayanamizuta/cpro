x,k=map(int,input().split())

for i in range(k):
    mod=x%(10**(i+1))
    if mod>=5*(10**(i)):
        x=(x//(10**(i+1))+1)*(10**(i+1))
    else:
        x=(x//(10**(i+1)))*(10**(i+1))
print(x)