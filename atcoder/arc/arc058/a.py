n, k = map(int, input().split())
d = list(map(int, input().split()))

while True:
    if all(map(lambda d_: str(d_) not in str(n), d)):
        print(n)
        exit()
    n += 1
