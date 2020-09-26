n__ = int(input())

mod = 1000000007
cnt = 0
for s in range(n__+1):
    for n in range(n__-s+1):
        for u in range(n__-(s+n)+1):
            for k in range(n__-(s+n+u)+1):
                for e in range(n__-(s+n+u+k)+1):
                    for s_ in range(s+1,n__-(s+n+u+k+e)+1):
                        for n_ in range(n+1,n__-(s+n+u+k+e+s_)+1):
                            for u_ in range(u+1,n__-(s+n+u+k+e+s_+n_)+1):
                                for k_ in range(k+1,n__-(s+n+u+k+e+s_+n_+u_)+1):
                                    for e_ in range(e+1,n__-(s+n+u+k+e+s_+n_+u_+k_)+1):
                                        if s+n+u+k+e+s_+n_+u_+k_+e_ <= n__:
                                            cnt += (s_-s)*(n_-n)*(u_-u)*(k_-k)*(e_-e) % mod
                                            cnt %= mod
print(cnt)


print(input()) #pythonだとこう

