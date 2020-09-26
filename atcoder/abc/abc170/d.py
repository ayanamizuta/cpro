n = int(input())
al = list(map(int,input().split()))

al.sort()
table = [False]*1000001
table2 = [False]*1000001

for a in al:
    if table2[a]:
        table[a]=True
    if not table[a]:
        table2[a] = True
        for i in range(a+a,1000001,a):
            table[i]=True
    

cnt=0
for a in al:
    if not table[a]:
        cnt+=1
print(cnt)