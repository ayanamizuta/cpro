n = int(input())
ps = []
for p in range(2,n+1):
    p_copy = p
    for pp in ps:
        p_ = pp[0]
        ind = 0
        if p_copy % p_ == 0:
            while p_copy % p_ == 0:
                p_copy //= p_
                ind += 1
        pp[1] = max(pp[1],ind)
    if p_copy != 1:
        ps.append([p_copy,1])
#print(ps)
ret = 1
for p,i in ps:
    ret *= p**i
print(ret+1)