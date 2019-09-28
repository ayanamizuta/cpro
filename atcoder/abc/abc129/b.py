n = int(input())
w = list(map(int,input().split()))
s=sum(w)
ret=s
l=0
for i in range(len(w)):
   l+=w[i] 
   s-=w[i]
   ret=min(ret,abs(s-l))
print(ret)
