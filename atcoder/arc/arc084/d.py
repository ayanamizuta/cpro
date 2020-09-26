k = int(input())
g = [[] for _ in range(k)]
for i in range(1,k):
    g[i].append([i*10%k,0])
    if i%10 != 9:
        g[i].append([(i+1)%k,1])
v = [100000]*k
v[1] = 1

def draw(d):
    for i in range(k):
        if v[i] > d:
            continue
        for v_next in g[i]:
            if v[i] == d and v_next[1] == 0 and v[v_next[0]] > d:
                v_n = v_next[0]
                while v[v_n] > d:
                    v[v_n] = d
                    v_n = v_n*10%k
            elif v[i] == d-1 and v_next[1] == 1 and v[v_next[0]] > d:
                v_n = v_next[0]
                while v[v_n] > d:
                    v[v_n] = d
                    v_n = v_n*10%k
            
for i in range(1,46):
    draw(i)
    if v[0] == i:
        print(v[0])
        exit()
