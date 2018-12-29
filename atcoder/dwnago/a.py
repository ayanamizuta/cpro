n=int(input())
a=list(map(int,input().split()))

s = sum(a)
for i in range(len(a)):
    a[i]*=n
a_diff = [abs(a[i]-s) for i in range(len(a))]
mi = min(a_diff)
#print(s)
#print(mi)
#print(a_diff)
for i in range(len(a_diff)):
    if a_diff[i] == mi:
        print(i)
        exit()
