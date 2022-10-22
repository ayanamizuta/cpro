n,m=map(int,input().split())
table={k:True for k in range(0,2*10**6+1)}
l = []
l.append(0)
table[0]=False
index=1
for i in range(n-2):
    while not table[index]:
        index+=1
    table[index]=False
    for x in l:
        if table.get(index*2-x):
            table[index*2-x]=False
        if table.get(x*2-index):
            table[x*2-index]=False
    l.append(index)

su = sum(l)
while not table[index] or (m-su-index)%n:
    index+=1

l.append(index)
dl = (m-su-index)//n
for i in range(n):
    l[i]+=dl
print(*l)

assert sum(l)==m