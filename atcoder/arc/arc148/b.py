n=int(input())
s=list(input())

start=-1
for i in range(n):
    if s[i]=="p":
        start=i
        break

def swp(a,b):
    ret=[s_ for s_ in s]
    for i in range(a,b+1):
        ret[i]="p" if s[b+a-i]=="d" else "d"
    return ret

minim = s
for i in range(start,n):
    swaped=swp(start,i)
    if minim>swaped:
        minim=swaped

print("".join(minim))
