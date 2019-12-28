n=int(input())

three_tmp = ["aac","b.c","bdd"]
four_tmp  = ["abcc","abdd","eegh","ffgh"]
five_tmp  = ["aabee","c.bff","cddgg","hij..","hij.."]
seven_tmp = ["aa..dee",".bb.d.f","..ccggf","h.iil..","h...lm.","...k.mn","jj.k..n"]

if n==2:
    print(-1)
elif n==3:
    for x in three_tmp:
        print(x)
elif n==4:
    for x in four_tmp:
        print(x)
elif n==5:
    for x in five_tmp:
        print(x)
elif n==6:
    for x in three_tmp:
        print(x+"."*3)
    for x in three_tmp:
        print("."*3+x)
elif n==7:
    for x in seven_tmp:
        print(x)
elif n==8:
    for x in four_tmp:
        print(x+"."*4)
    for x in four_tmp:
        print("."*4+x)
elif n==11:
    for x in four_tmp:
        print(x+"."*7)
    for x in seven_tmp:
        print("."*4+x)
else:
    res=n
    while res != 0:
        if res % 4 != 0:
            for x in five_tmp:
                print("."*(n-res) + x + "."*(res-5))
            res-=5
        else:
            for x in four_tmp:
                print("."*(n-res) + x + "."*(res-4))
            res-=4
