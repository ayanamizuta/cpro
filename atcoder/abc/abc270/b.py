x,y,z=map(int,input().split())


if x<y<0 or 0<y<x:
    if x<y<0 and z<y:
        print(-1)
        exit()
    elif x<y<z<0:
        print(abs(x))
    elif x<y<0<z:
        print(2*z+abs(x))

    if 0<y<x and z>y:
        print(-1)
        exit()
    elif 0<z<y<x:
        print(abs(x))
    elif z<0<y<x:
        print(-2*z+abs(x))
else:
    print(abs(x))