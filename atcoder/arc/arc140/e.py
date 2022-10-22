n,m=map(int,input().split())
def validate(arr):
    for i1 in range(n):
        for i2 in range(i1+1,n):
            for j1 in range(m):
                if arr[i1][j1]!=arr[i2][j1]:
                    continue
                for j2 in range(j1+1,m):
                    if arr[i1][j1]==arr[i1][j2] and arr[i1][j1]==arr[i2][j2]:
                        raise ValueError()


from itertools import permutations

def rotate(idx):
    return [x+1 for x in list(range(idx,25))+list(range(idx))]

arr=[]
for idx,permu in enumerate(permutations(range(25))):
    arr_in=[]
    for p in permu:
        arr_in.extend(rotate(p))
    arr.append(arr_in)
    if idx == 500:
        break

#validate(arr)
for i in range(n):
    print(arr[i][:m])