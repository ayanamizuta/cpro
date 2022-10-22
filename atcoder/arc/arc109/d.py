t = int(input())


def solve(ax,ay,bx,by,cx,cy):
    sx = ax ^ bx ^ cx
    sy = ay ^ by ^ cy
    if ax != sx:
        sx = ax
    else:
        sx = bx

    if ay != sy:
        sy = ay
    else:
        sy = by

    
    if set((ax,ay),(bx,by),(cx,cy)) == set((sx,sy),(sx,sy+1),(sx+1,sy)):
        if sx == sy:
            if sx == 0:
                print(0)
                return
            print(1+2*(sx))
            return
        print(2*max(abs(sx),abs(sy)))
        return 

    if set((ax,ay),(bx,by),(cx,cy)) == set((sx,sy),(sx,sy-1),(sx-1,sy)):
        if sx == sy:
            if sx == 0:
                print(2)
                return
            if sx == 1:
                print(1)
                return
            if sx > 0:
                print(2*(sx))
                return
            print(2+2*(-sx))
            return
        from math import floor
        m = floor(max(abs(sx-0.5),abs(sy-0.5)))
        print(1+2*m)
        return 
    if set((ax,ay),(bx,by),(cx,cy)) == set((sx,sy),(sx,sy-1),(sx+1,sy)):
        if (sx,sy) == (0,0) or (sx,sy) == (0,1):
            print(1)
            return
        sx_ = abs(sx)
        sy_ = abs(sy)
        if sx_ > sy_:
            print()

        if sx == sy:
            if sx == 0:
                print(2)
                return
            if sx == 1:
                print(1)
                return
            if sx > 0:
                print(2*(sx))
                return
            print(2+2*(-sx))
            return
        from math import floor
        m = floor(max(abs(sx-0.5),abs(sy-0.5)))
        print(1+2*m)
        return 
    return solve(ay,ax,by,bx,cy,cx)

for _ in range(t):
    ax,ay,bx,by,cx,cy = map(int,input().split())
    solve(ax,ay,bx,by,cx,cy)