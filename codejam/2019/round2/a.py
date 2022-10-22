from fractions import Fraction

def solve(pn):
    n=int(input())
    c = [list(map(int,input().split())) for _ in range(n)]
    slopes = set([])
    for i in range(n):
        for j in range(i+1,n):
            if (c[i][0]-c[j][0])*(c[i][1]-c[j][1])<0:
                slopes.add(Fraction(c[i][0]-c[j][0],c[i][1]-c[j][1]))
    
    print(f"Case #{pn}: {len(slopes)+1}")

t=int(input())
for i in range(t):
    solve(i+1)