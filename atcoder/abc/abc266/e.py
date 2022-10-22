n=int(input())

def next_exp(num,denom):
    for i in range(1,7):
        if i*denom > num:
            cur_num=sum(range(i,7))
            cur_denom = len(list(range(i,7)))
            return denom*cur_num+(6-cur_denom)*num, 6*denom

ret_num=0
ret_denom=1
for _ in range(n):
    ret_num,ret_denom=next_exp(ret_num,ret_denom)
print(ret_num/ret_denom)