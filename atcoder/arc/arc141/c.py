n=int(input())
p=list(map(lambda x:int(x)-1,input().split()))
q=list(map(lambda x:int(x)-1,input().split()))

if n==1:
    if p[0]!=q[0]:
        print(-1)
        exit()
    if p[0]==0:
        print("()")
        exit()
    if p[0]==1:
        print(")(")
        exit()

table = [None]*(2*n)

def put_with_validation(i,value):
    if (table[i] is not None) and table[i]!=value:
        print(-1)
        exit()
    table[i]=value

p_fst, p_last = p[0],p[-1]
q_fst, q_last = q[0],q[-1]
put_with_validation(p_fst,"(")
put_with_validation(p_last,")")
put_with_validation(q_fst,"(")
put_with_validation(q_last,")")

for i in range(2*n-1):
    if p[i]>p[i+1]:
        if i > 0:
            put_with_validation(p[i-1],")")
        put_with_validation(p[i],"(")
        put_with_validation(p[i+1],")")
        if i < 2*n-2:
            put_with_validation(p[i+2],"(")
    if q[i]<q[i+1]:
        if i > 0:
            put_with_validation(q[i-1],")")
        put_with_validation(q[i],"(")
        put_with_validation(q[i+1],")")
        if i < 2*n-2:
            put_with_validation(q[i+2],"(")

if None in table:
    print(-1)
    exit()

cnt = 0
for i in range(2*n):
    if table[p[i]]=="(":
        cnt+=1
    else:
        cnt-=1
    if cnt < 0:
        print(-1)
        exit()

if cnt:
    print(-1)
    exit()
cnt = 0
for i in range(2*n):
    if table[q[i]]=="(":
        cnt+=1
    else:
        cnt-=1
    if cnt < 0:
        print(-1)
        exit()
if cnt:
    print(-1)
    exit()
print("".join(table))
