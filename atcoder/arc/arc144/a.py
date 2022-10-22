n=int(input())
m=2*n

digit4 = n//4
res=n%4
if res==0:
    ret=int("4"*digit4)
else:
    ret=int(str(res)+"4"*digit4)

print(m)
print(ret)