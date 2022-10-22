s=input()
orig="atcoder"
ret=0
for i in range(7):
    for j in range(i+1,7):
        if s.index(orig[i])>s.index(orig[j]):
            ret+=1
print(ret)