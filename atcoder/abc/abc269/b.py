ss=[input() for _ in range(10)]
a,b,c,d=10,0,10,0
for i,s in enumerate(ss):
    a_ = s.find("#")
    b_ = 10-s[::-1].find("#")
    if a_ !=-1:
        a=min(a,i+1)
        b=max(b,i+1)
        c=a_+1
        d=b_

print(a,b)
print(c,d)