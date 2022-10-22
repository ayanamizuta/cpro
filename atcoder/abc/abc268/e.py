n=int(input())
p=list(map(int,input().split()))


def diff(d):
    if d>(n+1)//2:
        d-=n
    if d<-((n-1)//2):
        d+=n
    return d
p_after=[diff(p[i]-i) for i in range(n)]
negs = list(filter(lambda x:x<=0,p_after))
poss = list(filter(lambda x:x>0,p_after))
import heapq
heapq.heapify(negs)
heapq.heapify(poss)

cur=sum(abs(x) for x in negs) + sum(poss)
ret=cur
#print(cur)
for i in range(1,n):
    cur-=len(poss)-len(negs)
    #print(poss,negs,cur)
    while len(poss):
        top = heapq.heappop(poss)
        if top-i<=0:
            heapq.heappush(negs,top)
        else:
            heapq.heappush(poss,top)
            break
    while len(negs):
        top = heapq.heappop(negs)
        if n%2 and (top-i)==-(n+1)//2:
            heapq.heappush(poss,top+n)
            cur-=1
        elif top-i<=-n//2:
            heapq.heappush(poss,top+n)
        else:
            heapq.heappush(negs,top)
            break
    ret=min(ret,cur)
print(ret)