k,n=map(int,input().split())
mod=1000000007
vec=[1]+[0]*(k-1)
def plus(v):
    tmp=sum(v)%mod
    return v[1:]+[tmp]

def doub(v):
    v_in=v
    mat=[[0]*k for i in range(k)]
    for i in range(k):
        mat[i] = v_in
        v_in=plus(v_in)
    v_in=[0]*k
    for i in range(k):
        for j in range(k):
            v_in[i] += mat[i][j]*v[j]
            v_in[i]%=mod
    return v_in
    
bytestr = bin(n-1)[2:]
for x in bytestr:
    vec=doub(vec)
    if x=='1':
        vec=plus(vec)
print(vec)
print(sum(vec)%mod)
