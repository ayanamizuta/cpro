n,l,r=map(int,input().split())

def cnt(x):
    if x>r or 2*x<=l:
        return 0
    return min(2*x-1,r)-max(x,l)+1

ret=0
for i in range(64):
    if (n >> i)%2:
        ret+=cnt(2**i)

print(ret)