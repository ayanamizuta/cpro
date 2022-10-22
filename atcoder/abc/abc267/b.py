s=input()
s=[0]+[int(s_) for s_ in list(s)]

if s[1]==1:
    print("No")
    exit()

group = [[7],[4],[2,8],[1,5],[3,9],[6],[10]]

def vac(i):
    return all(map(lambda x:s[x]==0,group[i]))

def any_i(group_is):
    for i in group_is:
        if not vac(i):
            return True
    return False

def yes():
    print("Yes")
    exit()

for i in range(1,5):
    if vac(i):
        if any_i(list(range(i))) and any_i(list(range(i+1,7))):
            yes()
print("No")