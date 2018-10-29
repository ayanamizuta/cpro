n,m=map(int,input().split())
from math import sqrt,floor
k=1
divisor = []
sq = floor(sqrt(m))+2
while k < sq:
    if m%k==0:
        divisor += [k]
    k+=1

for v in divisor:
    if v >= n:
        print(m//v)
        exit()
divisor.reverse()
for v in divisor:
    if v <= m//n:
        print(v)
        exit()
