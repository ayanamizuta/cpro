ax,ay=map(int,input().split())
bx,by=map(int,input().split())
cx,cy=map(int,input().split())
dx,dy=map(int,input().split())

def jud(a,b,c,d,e,f):
    a-=c
    e-=c
    b-=d
    f-=d
    e_ = a*e+b*f
    f_= -b*e+a*f
    return f_<0

if jud(ax,ay,bx,by,cx,cy) and jud(bx,by,cx,cy,dx,dy) and jud(cx,cy,dx,dy,ax,ay) and jud(dx,dy,ax,ay,bx,by):
    print("Yes")
else:
    print("No")