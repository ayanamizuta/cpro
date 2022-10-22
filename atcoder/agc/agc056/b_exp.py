n,m=map(int,input().split())
lr = [list(map(int,input().split())) for _ in range(m)]
lr_range = [list(range(lr_[0],lr_[1]+1)) for lr_ in lr]
from itertools import product
from tqdm import tqdm

ret = 0
for a in tqdm(product(*lr_range)):
    bl=True
    for i in range(m):
        if not bl:
            break
        for j in range(i+1,m):
            intersection = set(list(range(lr[i][0],lr[i][1]+1))).intersection(set(list(range(lr[j][0],lr[j][1]+1))))
            if a[i] in list(intersection) and a[j] in list(intersection) and a[i]!=a[j]:
                #print(a)
                bl=False
                break
    if bl:
        ret+=1

print(ret)