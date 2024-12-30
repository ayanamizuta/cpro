n=int(input())
lr_list=[list(map(int,input().split())) for _ in range(2**n)]
lr = [x for l,r in lr_list for x in [l,r]]
lr_unique = list(set(lr))
lr_unique.sort()
lr_map = {x:i for i,x in enumerate(lr_unique)}

acm_right = [0]*(len(lr_unique)+1)
acm_left = [0]*(len(lr_unique)+1)

for l,r in lr_list:
    acm_right[lr_map[r]]+=1
    acm_left[lr_map[l]]+=1

print(acm_right,acm_left)

for i in range(len(lr_unique)):
    acm_right[i+1] += acm_right[i]
    acm_left[len(lr_unique)-i-1] += acm_left[len(lr_unique)-i]

cnt = 10**20

for i in range(len(lr_unique)):
    cnt = min(cnt,acm_left[i]+acm_right[i])

print(cnt)