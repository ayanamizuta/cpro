from collections import Counter
n=int(input())
lr=[list(map(int,input().split())) for _ in range(2**n)]

numbers = [x for lr_ in lr for i,x in enumerate(lr_)]
cnter = Counter(numbers)

numbers = list(set(numbers))
numbers.sort()

cnt = 0
for l,_ in lr:
    cnt+=l
ans=cnt
pre = 0
acm=-len(lr)
for x in numbers:
    n = cnter[x]
    print(x,n,pre,cnt,ans,acm)
    cnt = cnt+acm*(x-pre)
    ans = min(ans,cnt)
    acm += n
    pre = x

print(ans)