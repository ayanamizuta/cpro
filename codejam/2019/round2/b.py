
memo={}
def action(i,forge=None,myvase=None):
    if i<=19:
        print(i,100)
        return
    if 71<i and i<=80:
        print(i-60,0)
        memo[i-60]=[list(map(int,input().split())),i]
        return
    if i==100:
        print(20,100)
        return
    if forge is None:
        print(i%11+1,1)
        return
    ret=0
    for i in range(1,100):
        if i not in memo[forge][0]:
            memo[forge][0].append(i)
            print(forge,i)
            return

def solve():
    for i in range(80):
        action(int(input()))
    data = [[vase,len(memo[vase][0])+(80-memo[vase][1])/20,memo[vase]] for vase in memo.keys()]
    data = sorted(data,key=lambda x:x[1])
    forges=data[1:]
    for i in range(80,99):
        action(int(input()),forge=forges[i%len(forges)][0])
    action(int(input()),myvase=data[0][0])

t=int(input())
for _ in range(t):
    solve()