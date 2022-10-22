n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
rest_a=[]
ptr=0
while True:
    if ptr==2*n-1:
        rest_a.append(a[ptr])
        break
    if ptr>=2*n-1:
        break
    if a[ptr]==a[ptr+1]:
        ptr+=2
        continue
    else:
        rest_a.append(a[ptr])
    ptr+=1

if m%2==1:
    if rest_a:
        print("Alice")
    else:
        print("Bob")
else:
    set_rest_a = set(rest_a)
    cnt=0
    #print(rest_a)
    for rest_a_ in rest_a:
        if (rest_a_+m//2)%m in set_rest_a:
            cnt+=1
        else:
            print("Alice")
            exit()
    cnt//=2
    #print(cnt)
    if cnt%2==0:
        print("Bob")
    else:
        print("Alice")