from itertools import combinations
bits=0
ret=0
n=4
forbidden=[
    [1,2,3,4],
    [1,2,5,6],
    [1,2,7,8],
    [3,4,5,6],
    [3,4,7,8],
    [5,6,7,8]
]
forbidden2=[
    [1,2,3,4],
]

def include(bts,forb):
    for i in forb:
        if not ((bts>>(i-1)) & 1):
            return False
    return True

def violate(bts):
    arr = []
    for i in range(2**n):
        if (bts>>i)&1:
            arr.append(i)
    for cmb in combinations(arr,4):
        if cmb[0]^cmb[1]^cmb[2]^cmb[3]==0:
            return True
    for cmb in combinations(arr,6):
        if cmb[0]^cmb[1]^cmb[2]^cmb[3]^cmb[4]^cmb[5]==0:
            return True
    for cmb in combinations(arr,8):
        if cmb[0]^cmb[1]^cmb[2]^cmb[3]^cmb[4]^cmb[5]^cmb[6]^cmb[7]==0:
            return True
    for cmb in combinations(arr,10):
        if cmb[0]^cmb[1]^cmb[2]^cmb[3]^cmb[4]^cmb[5]^cmb[6]^cmb[7]^cmb[8]^cmb[9]==0:
            return True
    return False

def popcount(bts):
    ret=0
    for i in range(2**n):
        if (bts>>i)&1:
            ret+=1
    return ret

maxret=0
while bits<2**(2**n):
    if not violate(bits):
        ret+=1
        maxret=max(maxret,popcount(bits))
    bits+=1

print(ret,maxret)