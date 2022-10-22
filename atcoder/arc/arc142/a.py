n,k=map(int,input().split())

def flip(i):
    return int(str(i)[::-1])

def mini(i,init=10**13):
    if i <= flip(i) and i<= flip(flip(i)):
        return i
    return min(i,mini(flip(i),i))


st = set([])
cand=k
while True:
    if cand > n:
        break
    if mini(cand) == k:
        st|=set([cand])
    cand *= 10

cand = flip(k)
while True:
    if cand > n:
        break
    if mini(cand) == k:
        st|=set([cand])
    cand *= 10
print(len(st))