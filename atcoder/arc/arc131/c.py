n=int(input())
a=list(map(int,input().split()))

su_xor=0
for a_ in a:
    su_xor ^= a_
if su_xor in a:
    print("Win")
else:
    if n%2:
        print("Win")
    else:
        print("Lose")

