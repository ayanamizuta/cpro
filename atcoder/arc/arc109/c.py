n,k = map(int,input().split())
s = input()

def win(a,b):
    if (a,b) == ('R','R') or (a,b) == ('R','S') or (a,b) == ('S','R'):
        return 'R'
    if (a,b) == ('S','S') or (a,b) == ('S','P') or (a,b) == ('P','S'):
        return 'S'
    return 'P'

def red(ss):
    return [win(ss[2*i],ss[2*i+1]) for i in range(len(ss)//2)]

while k:
    if len(s) % 2:
        s = red(s*2)
    else:
        s = red(s)
    k-=1
print(s[0])