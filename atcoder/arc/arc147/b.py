n=int(input())
p=list(map(int,input().split()))
p=[p_-1 for p_ in p]
a_needed=[False]*n
a_needed_odd=[]
a_needed_even=[]
for i in range(n):
    a_needed[i]=p[i]%2!=i%2
    if a_needed[i]:
        if i%2:
            a_needed_odd.append(i)
        else:
            a_needed_even.append(i)
commands=[]
def render_command():
    for c in commands:
        print(*c)

def swap(o,e):
    maxi=max([o,e])
    mini=min([o,e])
    while maxi-mini!=1:
        commands.append(('B',maxi-2+1))
        p[maxi-2],p[maxi]=p[maxi],p[maxi-2]
        maxi-=2
    commands.append(('A',mini+1))
    p[mini],p[mini+1]=p[mini+1],p[mini]

for od,ev in zip(a_needed_odd,a_needed_even):
    swap(od,ev)

for i in range(n):
    ind = p.index(i)
    while ind!=i:
        commands.append(('B',ind-2+1))
        p[ind-2],p[ind]=p[ind],p[ind-2]
        ind-=2

print(len(commands))
render_command()


