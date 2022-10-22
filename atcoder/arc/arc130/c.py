import sys

a=input()
b=input()
swap=False
if len(a) < len(b):
    a,b=b,a
    swap=True
from collections import Counter
cnta = Counter()
cntb = Counter()
for a_ in a:
    cnta[int(a_)]+=1
for b_ in b:
    cntb[int(b_)]+=1
cnta_cp=cnta.copy()
cntb_cp=cntb.copy()

history=[]
for i in range(1,10):
    max_ = min(cnta[i],cntb[9-i])
    cnta[i]-=max_
    cntb[9-i]-=max_
    history.append(max_)

flag=False
for i in range(1,10):
    su = sum([cntb[9-j] for j in range(i)])
    max_ = min(cnta[i],su)
    if max_:
        flag=True
    cnta[i]-=max_
    cntb[9-i]-=max_
    history.append(max_)

pair = None
for i in range(1,10):
    su = sum([cntb_cp[9-j] for j in range(i)])
    if cnta_cp[i] and su:
        for j in range(i):
            if cntb_cp[9-j]:
                pair = (i,9-j)
                break
    if pair:
        break


if flag:
    if not swap:
        for i in range(9):
            numa = cnta_cp[i+1]-history[i]-history[i+9]
            sys.stdout.write(str(i+1)*numa)
        for i in range(9):
            numa = history[i]
            sys.stdout.write(str(i+1)*numa)
        for i in range(9):
            numa = history[i+9]
            sys.stdout.write(str(i+1)*numa)
        print()
        red = len(b)-sum(history)
        i=1
        while red:
            if cntb_cp[i]:
                mi=min(red,cntb_cp[i])
                sys.stdout.write(str(i)*mi)
                red-=mi
                cntb_cp[i]-=mi
            i+=1
        for i in range(9):
            sys.stdout.write(str(8-i)*history[i])
            cntb_cp[8-i]-=history[i]
        for i in range(9):
            red = history[9+i]
            j= 9-i
            while red:
                if cntb_cp[j]:
                    mi=min(red,cntb_cp[j])
                    sys.stdout.write(str(j)*mi)
                    red-=mi
                    cntb_cp[j]-=mi
                j+=1
        print()
    else:
        red = len(b)-sum(history)
        i=1
        while red:
            if cntb_cp[i]:
                mi=min(red,cntb_cp[i])
                sys.stdout.write(str(i)*mi)
                red-=mi
                cntb_cp[i]-=mi
            i+=1
        for i in range(9):
            sys.stdout.write(str(8-i)*history[i])
            cntb_cp[8-i]-=history[i]
        for i in range(9):
            red = history[9+i]
            j= 9-i
            while red:
                if cntb_cp[j]:
                    mi=min(red,cntb_cp[j])
                    sys.stdout.write(str(j)*mi)
                    red-=mi
                    cntb_cp[j]-=mi
                j+=1
        print()
        for i in range(9):
            numa = cnta_cp[i+1]-history[i]-history[i+9]
            sys.stdout.write(str(i+1)*numa)
        for i in range(9):
            numa = history[i]
            sys.stdout.write(str(i+1)*numa)
        for i in range(9):
            numa = history[i+9]
            sys.stdout.write(str(i+1)*numa)
        print()

elif (not flag) and pair:
    if not swap:
        cnta_cp[pair[0]]-=1
        cntb_cp[pair[1]]-=1
        history[pair[0]-1]-=1
        for i in range(9):
            numa = cnta_cp[i+1]-history[i]-history[i+9]
            sys.stdout.write(str(i+1)*numa)
        for i in range(9):
            numa = history[i]
            sys.stdout.write(str(i+1)*numa)
        sys.stdout.write(str(pair[0]))
        print()
        red = len(b)-sum(history)-1
        i=1
        while red:
            if cntb_cp[i]:
                mi=min(red,cntb_cp[i])
                sys.stdout.write(str(i)*mi)
                red-=mi
                cntb_cp[i]-=mi
            i+=1
        for i in range(9):
            sys.stdout.write(str(8-i)*history[i])
            cntb_cp[8-i]-=history[i]
        sys.stdout.write(str(pair[1]))
        print()
    else:
        red = len(b)-sum(history)
        i=1
        while red:
            if cntb_cp[i]:
                mi=min(red,cntb_cp[i])
                sys.stdout.write(str(i)*mi)
                red-=mi
                cntb_cp[i]-=mi
            i+=1
        for i in range(9):
            sys.stdout.write(str(8-i)*history[i])
            cntb_cp[8-i]-=history[i]
        sys.stdout.write(str(pair[1]))
        print()
        cnta_cp[pair[0]]-=1
        cntb_cp[pair[1]]-=1
        history[pair[0]-1]-=1
        for i in range(9):
            numa = cnta_cp[i+1]-history[i]-history[i+9]
            sys.stdout.write(str(i+1)*numa)
        for i in range(9):
            numa = history[i]
            sys.stdout.write(str(i+1)*numa)
        sys.stdout.write(str(pair[0]))
        print()

else:
    if not swap:
        print(a)
        print(b)
    else:
        print(b)
        print(a)