n=int(input())
a=n//16
b=n%16
l=[str(i)for i in range(10)]+["A","B","C","D","E","F"]
print(str(l[a])+str(l[b]))