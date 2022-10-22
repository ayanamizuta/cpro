h,w=map(int,input().split())
cs = [list(input()) for _ in range(h)]
from itertools import product
for i,j in product(range(h),range(w)):
    if cs[i][j]==".":
        avoid = set()
        if i:
            avoid |= set([cs[i-1][j]])
        if i<h-1:
            avoid |= set([cs[i+1][j]])
        if j:
            avoid |= set([cs[i][j-1]])
        if j<w-1:
            avoid |= set([cs[i][j+1]])

        cs[i][j]=list(set(["1","2","3","4","5"])-avoid)[0]

for i in range(h):
    print("".join(cs[i]))