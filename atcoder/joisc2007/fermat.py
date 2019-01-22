p = int(input())
n = int(input())

def pow_mod(z,n,p):
    ret=1%p
    b=z%p
    while n!=0:
        if n%2!=0:
            ret=ret*b%p
        b=b*b%p
        n=n//2
    return ret

nums = [0]*p
for z in range(p):
    nums[pow_mod(z,n,p)]+=1
ret=0
cl = sum([1 for i in range(p) if nums[i]])
for i in range(p):
    ret+=nums[i]*nums[(p-i)%p]
for i in range(p):
    ret+=nums[i]*nums[(p-i+1)%p]*nums[1]*(cl-1)
print(ret)
