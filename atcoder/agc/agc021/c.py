n,m,a,b=map(int,input().split())

def no():
    print("NO")
    exit()

if n*m<(a+b)*2:
    no()

ret = [["." for _ in range(m)] for _ in range(n)]

def greedy_r(cntmax=a):
    cnt=cntmax
    for i in range(n):
        for j in range(m-1):
            if (ret[i][j],ret[i][j+1])==(".","."):
                ret[i][j],ret[i][j+1]="<",">"
                cnt-=1
                if cnt==0:
                    return True
    return False

def greedy_c(cntmax=b):
    cnt=cntmax
    for i in range(n-1):
        for j in range(m):
            if (ret[i][j],ret[i+1][j])==(".","."):
                ret[i][j],ret[i+1][j]="^","v"
                cnt-=1
                if cnt==0:
                    return True
    return False

if n%2==0:
    if not greedy_r():
        no()
    if not greedy_c():
        no()
elif m%2==0:
    if not greedy_c():
        no()
    if not greedy_r():
        no()
else:
    for i in range(0,n//2):
        for j in range(n//2-i):
            if b:
                ret[2*j+i][i],ret[2*j+1+i][i]="^","v"
                b-=1
        for j in range(n//2-i):
            if b:
                ret[2*j+1+i][-1-i],ret[2*j+2+i][-1-i]="^","v"
                b-=1

        for j in range(n//2-i):
            if a:
                ret[i][2*j+1+i],ret[i][2*j+i+2]="<",">"
                a-=1
        for j in range(n//2-i):
            if a:
                ret[-1-i][2*j+i],ret[-1-i][2*j+i+1]="<",">"
                a-=1
        if a==0 or b==0:
            break
    if a==0 and b!=0:
        if not greedy_c(cntmax=b):
            no()
    elif b==0 and a!=0:
        if not greedy_r(cntmax=a):
            no()


print("YES")
for x in ret:
    print("".join(x))