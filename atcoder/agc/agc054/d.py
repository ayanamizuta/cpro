s=input()
s="()oxo(xxx))))oox((oooxxoxo)oxo)ooo(xxx(oox(x)(x()x"
s=")oxoox(()"
ret=0

acm=0
stack=[]
s_arr=list(s)
for i,x in enumerate(s):
  if x=="(":
    acm+=1
    if len(stack):
      idx=stack.pop(0)
      ret+=i-idx
      del s_arr[i]
      s_arr.insert(idx,"(")
      for j in range(len(stack)):
        stack[j]+=1
  elif x==")":
    acm-=1
    if acm<0:
      stack.append(i)
  
print("".join(s_arr),ret)