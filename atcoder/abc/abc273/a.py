n=int(input())

def solve(k):
    if k==0:
        return 1
    return k*solve(k-1)
print(solve(n))