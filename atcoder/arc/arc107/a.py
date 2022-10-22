a,b,c = map(int,input().split())
mod = 998244353
ret = 1
ret *= a*(a+1)//2
ret %= mod
ret *= b*(b+1)//2
ret %= mod
ret *= c*(c+1)//2
ret %= mod
print(ret)