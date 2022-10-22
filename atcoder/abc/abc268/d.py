from itertools import permutations, combinations
n,m=map(int,input().split())
s=[input() for _ in range(n)]
t={input():True for _ in range(m)}

cat_length = sum(len(s_) for s_ in s)

for tup in permutations(range(n),n):
    for tupc in combinations(range(16-cat_length+1),n):
        #print(tup,tupc)
        underbar_nums = [tupc[i+1]-tupc[i] for i in range(n-1)]
        s_cat = ""
        for i in range(n-1):
            s_cat+=s[tup[i]]+"_"*underbar_nums[i]
        s_cat += s[tup[n-1]]
        if len(s_cat)<3 or len(s_cat)>16:
            continue
        if t.get(s_cat):
            continue
        else:
            print(s_cat)
            exit()
print(-1)