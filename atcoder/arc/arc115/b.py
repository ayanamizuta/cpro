n = int(input())
c = [[]*n]*n
for i in range(n):
    c[i] = list(map(int,input().split()))

cand = c[0]
m = min(cand)
cand = [x-m for x in cand]

for i in range(1,n):
    base  = c[i][0] - cand[0]
    for j in range(1,n):
        if base < 0 or base != c[i][j] - cand[j]:
            print("No")
            exit()
    
def pp(l):
    print(" ".join((map(lambda x:str(x),l))))

print("Yes")
pp([c[i][0] - cand[0] for i in range(n)])
pp(cand)