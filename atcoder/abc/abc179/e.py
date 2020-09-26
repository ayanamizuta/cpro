n,x,m = map(int,input().split())

table = [0]*m

def calc(init,iter):
    ret = 0
    for _ in range(iter):
        ret += init
        init = (init*init)%m
    return ret

ret = x
cur = x % m
table[cur] = 1
for rnd in range(2,min(m+2,n+1)):
    cur = (cur*cur) % m
    if table[cur]:
        per = rnd - table[cur]
        persum = calc(cur,per)
        rnds = (n - rnd) // per
        ret += rnds*persum
        ret += calc(cur,n - rnd - per*rnds+1) 
        #print(cur,table[cur],rnd,per,persum,rnds)
        break
    else:
        table[cur] = rnd
        ret += cur



print(ret)