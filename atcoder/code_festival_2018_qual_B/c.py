n=int(input())
mods = [0,3,1,4,2]
marked = [[0]*n for x in range(n)]
for x in range(n):
    for y in range(n):
        if y % 5 == mods[x % 5]:
            marked[x][y] += 1

def nbh(x,y):
    if x > 0 and marked[x-1][y]:
        return True
    if y > 0 and marked[x][y-1]:
        return True
    if x < n-1 and marked[x+1][y]:
        return True
    if y < n-1 and marked[x][y+1]:
        return True
    return False

for x in range(n):
    for y in range(n):
        if not nbh(x,y):
            marked[x][y] = 1

for x in range(n):
    for y in range(n):
        if marked[x][y] == 1:
            print("X",end="")
        else:
            print(".",end="")
    print()

#print(sum([sum(marked[x]) for x in range(n)]))
