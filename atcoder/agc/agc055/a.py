n=int(input())
s=input()
mat=[[0 for _ in range(3)] for _ in range(3)]
for i in range(3):
  for j in range(i*n,(i+1)*n):
    if s[j]=="A":
      mat[i][0]+=1
    elif s[j]=="B":
      mat[i][1]+=1
    else:
      mat[i][2]+=1

a=[-1]*6
a0=0
while min(a)<0:
  a[0]=a0
  a[1]=mat[0][0]-a[0]
  a[5]=mat[1][1]-a[0]
  a[4]=mat[0][2]-mat[1][1]+a[0]
  a[2]=mat[1][0]-mat[0][2]+mat[1][1]-a[0]
  a[3]=mat[0][1]-a[2]
  a0+=1
out=[0]*(3*n)


acm=0
for i in range(3*n):
  if s[i]=="A":
    acm+=1
    if acm<=a[0]:
      out[i]=1
    elif acm<=a[0]+a[1]:
      out[i]=2
    elif acm<=a[0]+a[1]+a[2]:
      out[i]=3
    elif acm<=a[0]+a[1]+a[2]+a[4]:
      out[i]=5
    elif acm<=a[0]+a[1]+a[2]+a[4]+a[3]:
      out[i]=4
    else:
      out[i]=6

acm=0
for i in range(3*n):
  if s[i]=="B":
    acm+=1
    if acm<=a[2]:
      out[i]=3
    elif acm<=a[2]+a[3]:
      out[i]=4
    elif acm<=a[2]+a[3]+a[0]:
      out[i]=1
    elif acm<=a[2]+a[3]+a[0]+a[5]:
      out[i]=6
    elif acm<=a[2]+a[3]+a[0]+a[5]+a[1]:
      out[i]=2
    else:
      out[i]=5

acm=0
for i in range(3*n):
  if s[i]=="C":
    acm+=1
    if acm<=a[4]:
      out[i]=5
    elif acm<=a[4]+a[5]:
      out[i]=6
    elif acm<=a[4]+a[5]+a[1]:
      out[i]=2
    elif acm<=a[4]+a[5]+a[1]+a[3]:
      out[i]=4
    elif acm<=a[4]+a[5]+a[1]+a[3]+a[0]:
      out[i]=1
    else:
      out[i]=3

print("".join(map(lambda x:str(x),out)))

