n=int(input())
s=input()

def nc2(n):
    if n<2:
        return 0
    return n*(n-1)//2

ret=0
now=None
cnt=0
s+="*"
for i in range(n+1):
    if now is None:
        now=s[i]
        cnt=1
    elif now==s[i]:
        cnt+=1
    else:
        now=s[i]
        ret+=nc2(cnt)
        cnt=1
print(ret)