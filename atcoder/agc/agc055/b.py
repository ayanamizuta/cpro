n=int(input())
s=input()
t=input()
if s.count("A")!=t.count("A") or s.count("B")!=t.count("B") or s.count("C")!=t.count("C"):
  print("NO")
  exit()

s_stopper=[i for i in range(1,n-1) if s[i-1:i+2] in ["CBA","BAC","ACB"]]
t_stopper=[i for i in range(1,n-1) if t[i-1:i+2] in ["CBA","BAC","ACB"]]

if s_stopper!=t_stopper:
  print("NO")
  exit()
  
for i in s_stopper:
  if s[i]!=t[i]:
    print("NO")
    exit()

def mod(a):
  if a=="A":
    return 0
  elif a=="B":
    return 1
  return 2

def invariant(s):
  sn=0
  for i in range(len(s)):
    sn+=(i%3)*mod(s[i])
  return sn%3

s_stopper = [-1]+s_stopper+[n]

for i in range(len(s_stopper)-1):
  begin=s_stopper[i]+1
  end=s_stopper[i+1] 
  if invariant(s[begin:end])!=invariant(t[begin:end]):
    print("NO")
    exit()

print("YES")