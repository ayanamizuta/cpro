
t = int(input())
def inc(i,l):
    if l[i+1] > l[i]:
        return 0
    nex = str(l[i+1])
    pre = str(l[i])
    if pre[:len(nex)] == nex and not all(map(lambda x:x=="9",pre[len(nex):])):
        l[i+1] = l[i]+1
        return len(pre)-len(nex)
    ret = 0
    #print(i,l[i],l[i+1])
    while True:
        for j in range(10):
            if l[i] < 10*l[i+1]+j:
                l[i+1] = 10*l[i+1]+j
                return ret+1
        l[i+1] = 10*l[i+1]
        ret+=1

def solve_one(pn):
    n = int(input())
    l = list(map(int,input().split()))
    ret = 0
    for i in range(n-1):
        ret += inc(i,l)
    print(f"Case #{pn}: {ret}")

for i in range(t):
    solve_one(i+1) 