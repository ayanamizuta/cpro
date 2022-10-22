n=int(input())
trie={"exist":0,"value":0,"trie":{}}
ss = [input() for _ in range(n)]
for i in range(n):
    s=ss[i]
    inner_trie=trie["trie"]
    for j,s_ in enumerate(s):
        if(inner_trie.get(s_)):
            inner_trie[s_]["value"]+=1
            if j==len(s)-1:
                inner_trie[s_]["exist"]=1
            inner_trie = inner_trie[s_]["trie"]
        else:
            inner_trie[s_]={"exist":0,"value":1,"trie":{}}
            if j==len(s)-1:
                inner_trie[s_]["exist"]=1
            inner_trie = inner_trie[s_]["trie"]

mod = 998244353
#print(trie)
for s_i in ss:
    ret=0
    nor_pre_suf=0
    inner_trie=trie
    for i,s_ in enumerate(s_i):
        #if i == len(s_i)-1:
        #    break
        #print(s_i,inner_trie)
        if inner_trie["trie"][s_].get("exist"):
            ret += inner_trie["trie"][s_]["exist"]
        inner_trie=inner_trie["trie"][s_]
    if inner_trie.get("value"):
        nor_pre_suf = n - ret - inner_trie["value"]+1
    else:
        nor_pre_suf = n - ret+1
    #print(ret,nor_pre_suf)
    print((ret+499122177*nor_pre_suf)%mod)
