

def max_swaps(swap_table):
    odds=0
    evens=0
    for i in range(len(swap_table)):
        for j in range(len(swap_table[i])):
            if swap_table[i][j] and (i+j)%2:
                odds+=1
            elif swap_table[i][j]:
                evens+=1
    return min(odds,evens)

# only visible
def solve(pn):
    r,c,f,s=map(int,input().split())
    table_start=[input() for _ in range(r)]
    table_goal=[input() for _ in range(r)]
    diffs=0
    for i in range(r):
        for j in range(c):
            if table_start[i][j] != table_goal[i][j]:
                diffs+=1

    swaps = []
    for i in range(r):
        for j in range(c-1):
            if table_start[i][j] != table_start[i][j+1] and table_start[i][j] != table_goal[i][j] and table_start[i][j+1] != table_goal[i][j+1]:
                swaps.append([[i,j],[i,j+1]])
    for i in range(r-1):
        for j in range(c):
            if table_start[i][j] != table_start[i+1][j] and table_start[i][j] != table_goal[i][j] and table_start[i+1][j] != table_goal[i+1][j]:
                swaps.append([[i,j],[i+1,j]])

    if not len(swaps):
        print(f"Case #{pn}: {diffs}")
        return

    ret=0
    visited = [False]*len(swaps)
    for i in range(len(swaps)):
        if visited[i]:
            continue
        visited[i]=True
        swap=swaps[i]
        swap_table = [[False for _ in range(c)] for _ in range(r)]
        swap_table[swap[0][0]][swap[0][1]]=True
        swap_table[swap[1][0]][swap[1][1]]=True
        while True:
            bl=True
            for j in range(len(swaps)):
                if visited[j]:
                    continue
                swap_=swaps[j]
                if swap_table[swap_[0][0]][swap_[0][1]] or swap_table[swap_[1][0]][swap_[1][1]]:
                    visited[j]=True
                    bl=False
                    swap_table[swap_[0][0]][swap_[0][1]]=True
                    swap_table[swap_[1][0]][swap_[1][1]]=True
            if bl:
                break
        ret+=max_swaps(swap_table)
    print(f"Case #{pn}: {diffs-ret}")

t=int(input())
for i in range(t):
    solve(i+1)