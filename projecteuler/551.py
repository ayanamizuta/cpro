from typing import Dict 
from tqdm import tqdm
from multiprocessing import Pool
import os

def digit_sum(n: int) -> int:
    ret = 0
    while n:
        ret += n%10
        n //= 10
    return ret

def naive(n:int) -> int:
    ret = 1
    memo = 1
    while n:
        ret = memo
        memo += digit_sum(ret)
        n -= 1
    return ret

lower_digit_ = 7
table_n = 9*10
dic = [[None for _ in range(10**lower_digit_)] for _ in range(table_n)]
"""
def fill(upper_digit_sum,n,lower_digit: int = 8) -> (int,int):
    next_n = n + upper_digit_sum + digit_sum(n)
    if next_n >= 10**lower_digit:
        return (0,n)
    c,val = fill(upper_digit_sum,next_n)
    c+=1
    dic[(upper_digit_sum,n)] = (c,val)
    return (c,val)
"""

# avoid recursion
def fill(upper_digit_sum,n,lower_digit: int = 8):
    arr = []
    l = 0
    elem = None
    while n < 10**lower_digit:
        arr.append(n)
        l+=1
        elem = dic[upper_digit_sum][n]
        if elem:
            break
        n = n + upper_digit_sum + digit_sum(n)
    nn = l-1
    last = arr[nn]
    if elem:
        nn += elem[0]
        last = elem[1]
    for i,x in enumerate(arr[:-1]):
        dic[upper_digit_sum][x] = (nn-i,last)

def memo_sub(upper_digit_sum: int) -> list:
    lower_digit = lower_digit_
    for i in range(10**lower_digit):
        if upper_digit_sum == 0 and i == 0:
            continue
        if dic[upper_digit_sum][i]:
            continue
        fill(upper_digit_sum,i,lower_digit=lower_digit)
    print(f"done {upper_digit_sum}")
    return dic[upper_digit_sum]

def memo_naive(lower_digit: int = 8):
    for i in tqdm(range(table_n)):
        memo_sub(upper_digit_sum=i)

def memo_multiprocess(lower_digit: int = 8):
    p = Pool(os.cpu_count())
    result = p.map(memo_sub, range(table_n))
    for i,x in enumerate(result):
        dic[i] = x
    

def key(n:int,lower_digit: int = 8) -> (int,int):
    lower = int(str(n)[-lower_digit:])
    upper_digit_sum = digit_sum(n-lower)
    assert table_n > upper_digit_sum, f"too large {n}"
    return (upper_digit_sum,lower)

def skip_naive(n:int,lower_digit: int = 8) -> int:
    ret = 1
    index = 1
    ratio = 0
    while n != index:
        if index*1000//n > ratio:
            ratio = index*1000//n
            print(f"{ratio} %")
        c,v = key(ret,lower_digit=lower_digit)
        val = dic[c][v]
        if val and index + val[0] <= n:
            ret += val[1] - (ret % (10**lower_digit))
            index += val[0]
            continue

        ret += digit_sum(ret)
        index += 1
    return ret

if __name__ == "__main__":
    #print(naive(10**8))
    #memo_naive(lower_digit=lower_digit_)
    memo_multiprocess(lower_digit=lower_digit_)
    print("memo done")
    print(skip_naive(10**15,lower_digit=lower_digit_))