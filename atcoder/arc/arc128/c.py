import sys
sys.setrecursionlimit(100000)
n,m,s=map(int,input().split())
a=list(map(int,input().split()))
ret_x=[0]*n

suma=[0]*(n+1)
for i in range(n):
  suma[i+1]=suma[i]+a[i]

def solve_maxi(s,n):
  ret=0
  maxi=0
  for i in range(n):
    ret_in=0
    #for j in range(i,n):
    #  ret_in+=a[j]*s/(n-i)
    ret_in=(suma[n]-suma[i])*s/(n-i)
    if ret<ret_in:
      ret=max(ret,ret_in)
      maxi=i
  return maxi

def solve(s,n):
  if s<=0 or n<=0:
    return
  maxi=solve_maxi(s,n)
  if s>(n-maxi)*m:
    for i in range(maxi,n):
      ret_x[i]=m
    solve(s-(n-maxi)*m,maxi)
  else:
    for i in range(maxi,n):
      ret_x[i]=s/(n-maxi)

solve(s,n)

ret=0
for i in range(n):
  ret+=a[i]*ret_x[i]
print(ret)