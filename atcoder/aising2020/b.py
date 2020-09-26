n = int(input())
a = list(map(int,input().split()))
cnt=0
for i,a_ in enumerate(a):
    if i % 2 == 0 and a_ % 2 == 1:
        cnt+=1

print(cnt)