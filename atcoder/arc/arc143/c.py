n,x,y=map(int,input().split())
a=list(map(int,input().split()))

def iswin(amount,myturn):
    amount=amount % (x+y)
    if myturn:
        if amount >= x:
            return True
        return False
    if amount < y:
        return True
    return False

init_win = list(map(lambda x:iswin(x,True),a))
init_win_oppo = list(map(lambda x:iswin(x,False),a))
for i in range(n):
    if (not init_win[i]) and (not init_win_oppo[i]):
        print("Second")
        exit()
if not any(init_win):
    print("Second")
    exit()
print("First")