n=int(input())
s=input()
t=input()
if s.count("A")!=t.count("A") or s.count("B")!=t.count("B") or s.count("C")!=t.count("C"):
  print("NO")
  exit()

def standard(s):
  stack=[]
  for i in range(len(s)):
    if "".join(stack[-2:])+s[i] in ["ABC","BCA","CAB"]:
      stack.pop()
      stack.pop()
    else:
      stack.append(s[i])
  return stack
if standard(s)!=standard(t):
  print("NO")
else:
  print("YES")