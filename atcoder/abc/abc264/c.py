from itertools import combinations,product
h1,w1=map(int,input().split())
a=[list(map(int,input().split())) for _ in range(h1)]
h2,w2=map(int,input().split())
b=[list(map(int,input().split())) for _ in range(h2)]

def try_hw(hs,ws):
    for i in range(h2):
        i_a=hs[i]
        for j in range(w2):
            j_a=ws[j]
            if b[i][j]!=a[i_a][j_a]:
                return False
    return True
        
for hs,ws in product(combinations(range(h1),h2),combinations(range(w1),w2)):
    if try_hw(hs,ws):
        print("Yes")
        exit()
print("No")