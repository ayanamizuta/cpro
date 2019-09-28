r,g,b,n=map(int,input().split())
s = [r,g,b]
s.sort(reverse=True)
r,g,b=s[0],s[1],s[2]
"""
if r==1 and g == 1 and b==1:
    print(4504501)
    exit()
"""
cnt=0
for i in range(0,n//r+1):
    m = n - i*r
    for j in range(0,m//g+1):
        l = m - j*g
        if l%b==0:
            cnt+=1
print(cnt)

