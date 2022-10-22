from tqdm import tqdm
n=1000000
nsq=1500
table=[False]*(1000001)

def nc2(m):
    return m*(m-1)//2

def max_sq(x):
    lb=2
    ub=1500
    while lb<ub:
        mid=(lb+ub)//2
        if nc2(mid) < x:
            lb=mid+1
        else:
            ub=mid
    return lb

def decomp(x):
    idx=max_sq(x)
    if nc2(idx)==x:
        return [idx]
    elif nc2(idx)>x:
        idx-=1
    return [idx] + decomp(x-nc2(idx))
print(decomp(1))

print(max([len(decomp(x)) for x in range(2,n+1)]))