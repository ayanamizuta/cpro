n = int(input())
a = list(map(int, input().split()))
a_ = list(filter(lambda x: x >= 0, map(lambda x: x - n, a)))

if not a_ or (len(a_) % 2 == 0 and max(a_) == len(a_) - 1):
    print("Bob")
    exit()

if len(a_) == 2 and a_[0] // 2 == a_[1] // 2:
    print("Bob")
else:
    print("Alice")
