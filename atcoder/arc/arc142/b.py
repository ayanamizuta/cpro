


def render(arr):
    for a_ in arr:
        print(*a_)

def validate(arr):
    n_=len(arr)
    for i in range(1,n_-1):
        for j in range(1,n_-1):
            a_=arr[i][j]
            cnt=0
            for ii in range(-1,2):
                for jj in range(-1,2):
                    if (ii,jj)!=(0,0) and a_<arr[i+ii][j+jj]:
                        cnt+=1
            if cnt==4:
                raise ValueError(f"n:{n_} {arr} at {arr[i][j]}")
                        

n=int(input())
arr = [[0 for _ in range(n)] for _ in range(n)]

index=1
for i in range(n):
    for j in range(i+1):
        if arr[j][i-j]==0:
            arr[j][i-j]=index
            index+=1
    for j in range(i+1):
        if arr[j][n-1-i+j]==0:
            arr[j][n-1-i+j]=index
            index+=1
    for j in range(i+1):
        if arr[n-1-i+j][j]==0:
            arr[n-1-i+j][j]=index
            index+=1
    for j in range(i+1):
        if arr[n-1-j][n-1-i-j]==0:
            arr[n-1-j][n-1-i+j]=index
            index+=1
    print(arr)

"""center = (n//2,n//2)
def assign(init_cell,index,dir,ps=0):
    print(dir,arr,init_cell,ps)
    if index>n**2:
        return index
    i,j=init_cell
    if dir=="u":
        k = i - center[0]
        if k+ps <= 0:
            return index
        for offset in range(k+ps):
            if arr[i-offset][j]==0:
                arr[i-offset][j]=index
                index+=1
    elif dir=="r":
        k = center[1] - j
        if k+ps <= 0:
            return index
        for offset in range(k+ps):
            if arr[i][j+offset]==0:
                arr[i][j+offset]=index
                index+=1
    elif dir=="d":
        k = center[0] - i
        if k+ps <= 0:
            return index
        for offset in range(k+ps):
            if arr[i+offset][j]==0:
                arr[i+offset][j]=index
                index+=1
    elif dir=="l":
        k = j - center[1]
        if k+ps <= 0:
            return index
        for offset in range(k+ps):
            if arr[i][j-offset]==0:
                arr[i][j-offset]=index
                index+=1
    return index"""

"""lu = [0,0]
ru = [0,n-1]
ld = [n-1,0]
rd = [n-1,n-1]
init_index=1
while True:
    init_index=assign(lu,init_index,"r",ps=1)
    lu[0]+=1
    init_index=assign(lu,init_index,"d",ps=1)
    lu[1]+=1

    init_index=assign(ru,init_index,"l")
    ru[0]+=1
    init_index=assign(ru,init_index,"d",ps=1)
    ru[1]-=1

    init_index=assign(ld,init_index,"r",ps=1)
    ld[0]-=1
    init_index=assign(ld,init_index,"u")
    ld[1]+=1

    init_index=assign(rd,init_index,"l")
    rd[0]-=1
    init_index=assign(rd,init_index,"u")
    rd[1]-=1
    if init_index > n**2:
        break"""

validate(arr)
render(arr)