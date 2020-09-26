n,m=map(int,input().split())

def cnt_score(b):
    def cnt_score_sub(i1,i2,j1,j2):
        su=0
        for i in range(i1,i2+1):
            for j in range(j1,j2+1):
                su += b[i][j]
        if su % 2 == 1:
            return True
        return False
    cnt=0
    for i1 in range(2**n-1):
        for i2 in range(i1,2**n-1):
            for j1 in range(2**m-1):
                for j2 in range(j1,2**m-1):
                    if cnt_score_sub(i1,i2,j1,j2):
                        cnt+=1
    return cnt

def print_b(b):
    for x in b:
        print(x)

def itob(i):
    b = [[0]*(2**m-1) for _ in range((2**n-1))]
    for j in range((2**m-1)*(2**n-1)):
        if i & (1 << j) != 0:
            b[j//(2**m-1)][j%(2**m-1)] = 1
    return b

def btoi(b):
    ret = 0
    for i in range(2**n-1):
        for j in range(2**m-1):
            ret += b[i][j] << (j+i*(2**m-1))
    return ret

"""ma = 0
init = 0#btoi([[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,0,0],[1,1,1,1,1,1,1],[1,0,1,0,1,0,1],[1,1,1,1,1,1,1]])
for i in range(init,2**((2**n-1)*(2**m-1))):
    testa = cnt_score(itob(i))
    if ma <= testa:
        ma = testa
        print("score:",ma)
        print_b(itob(i))
"""
"""
b1 = [1,1,1,1,1,1,1]
b2 = [1,0,1,0,1,0,1]
b3 = [1,0,1,1,1,0,1]
b4 = [1,1,1,0,1,1,1]
b = [b1,b3,b1,b4,b1,b3,b1]
print("score:",cnt_score(b))
"""
b2 = [1,0,1,0,1,0,1]
b1_ = [1]*15
b2_ = b2+[1]+b2
b2__ = b2+[0]+b2
b = [b1_,b2__,b1_]
print("score:",cnt_score(b))