n=int(input())

primes=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]
rads=[]

for p in primes:
    t=1
    while p**t <= n:
        if p**(t+1) > n:
            rads += [p**t]
        t+=1

primes = primes[0:len(rads)]
from functools import reduce
def prod(iterable):
    return reduce(lambda x,y:x*y, iterable, 1)
denom = prod(rads)
nums = [denom//r for r in rads]
mods = [nums[idx] % rads[idx] for idx in range(len(rads))]
adds = [0]*len(nums)

q=0
s=[]
for idx in range(len(rads)):
    wid=1
    while True:
        if mods[idx]*wid % rads[idx] == 1:
            q+=wid
            s+=["+ "+str(rads[idx])]*wid
            adds[idx]=nums[idx]*wid
            break
        if mods[idx]*wid % rads[idx] == rads[idx]-1:
            q+=wid
            s+=["- "+str(rads[idx])]*wid
            adds[idx]=-nums[idx]*wid
            break
        wid+=1

num_1 = sum(adds)//denom
if num_1>0:
    q+=num_1
    s+=["- 1"]*(num_1)
elif num_1<0:
    q+=-num_1
    s+=["+ 1"]*(-num_1)
s.sort()

if n==1:
    print(1)
    print("+ 1")
    exit()
    
print(q)
#print([adds[idx]//nums[idx] for idx in range(len(nums))])
for st in s:
    print(st)
