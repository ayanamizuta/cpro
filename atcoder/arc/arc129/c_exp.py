from tqdm import tqdm
n=1000000
nsq=1500
table=[False]*(1000001)

def nc2(m):
    return m*(m-1)//2
idx=2
while nc2(idx)<=n:
    table[nc2(idx)]=True
    idx+=1

table2=[False]*(1000001)

for idx_pre in tqdm(range(2,nsq)):
    idx=nc2(idx_pre)
    for idy_pre in range(2,nsq):
        idy = nc2(idx_pre)
        if idx <= n:
            table2[idx]=True
        if idy <= n:
            table2[idy]=True
        if idx+idy<=n:
            table2[idx+idy]=True


table3=[False]*(1000001)
for idy in tqdm(range(1,n+1)):
    for idx_pre in range(2,nsq):
        idx=nc2(idx_pre)
        if idx<=n and idy<=n and table[idx] and table2[idy] and idx+idy<=n:
            table3[idx+idy]=True

for idx in range(1,n+1):
    table3[idx] = table3[idx] or table2[idx]

print(all(table3[1:]))