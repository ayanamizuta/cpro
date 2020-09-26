a,v = map(int,input().split())
b,w = map(int,input().split())
t = int(input())

if w-v>=0:
    print("NO")
elif (abs(a-b)-1)//(v-w) < t:
    print("YES")
else:
    print("NO")