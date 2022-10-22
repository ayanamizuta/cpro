x=int(input())

digits = []
for i in range(61):
    if x>>i&1:
        digits.append(i)
    
def make(bits):
    ret=0
    for i in range(len(digits)):
        if bits>>i&1:
            ret+=1<<digits[i]
    return ret

numbers=[]
bits = 0
while bits<2**len(digits):
    numbers.append(make(bits))
    bits+=1

numbers.sort()
for n in numbers:
    print(n)