n = int(input())



from math import cos,sin,pi

x,y=[0,0]
rad = 0
for i in range(10000):
    x += cos(pi*rad*n/180)
    y += sin(pi*rad*n/180)
    rad+=1
    if abs(x) < 0.00001 and abs(y) < 0.00001:
        print(i+1)
        exit()