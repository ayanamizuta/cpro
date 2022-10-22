

def solve(n):
    for i in range(99):
        print(f"M {i+1} {n}")
        s=int(input())
        if s != i+1:
            print(f"S {i+1} {s}")
            s_=input()
    print(f"D")
    s_=input()

t,n=map(int,input().split())
for i in range(t):
    solve(n)