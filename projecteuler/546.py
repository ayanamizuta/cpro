from math import floor

def naive_f(k:int, n:int) -> int:
    if n == 0:
        return 1
    ret = 0
    for i in range(n+1):
        ret += naive_f(k,floor(i/k))
    return ret


if __name__ == "__main__":
    print(naive_f(5,10))
    print(naive_f(7,100))
    print(naive_f(2,1000))