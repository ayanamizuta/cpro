from math import gcd
n=int(input())
a=list(map(int,input().split()))
a_2_set=set([a_%2 for a_ in a])

if len(a_2_set)==1:
    print(1)
    exit()

a_unique=list(set(a))
a_unique.sort()
a_unique_diff=[a_unique_-a_unique[0] for a_unique_ in a_unique]

ret=a_unique_diff[1]
for i in range(1,len(a_unique_diff)):
    ret=gcd(ret,a_unique_diff[i])
if ret>1:
    print(1)
else:
    print(2)