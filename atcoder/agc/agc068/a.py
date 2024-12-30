from collections import deque, defaultdict

n = int(input())
a = list(map(int, input().split()))

next_indices = defaultdict(list)
for index, a_ in enumerate(a):
    next_indices[a_].append(index)

for key in next_indices.keys():
    next_indices[key] = next_indices[key][1:] + next_indices[key][:1]

remain = deque(list(range(n)))
lower1 = deque(list(range(n)))
s = [0] * n
t = [1] * n
while len(remain):
    now = remain.popleft()
    lis = next_indices[a[now]]
    left = lower1.popleft()
    if not lis:
        s.append(1)
        t.append(1)
        remain.appendleft(now)
        lower1.append(left)
        continue
    if lis and lis[0] == left:
        s.append(1)
        t.append(0)
        del next_indices[a[now]][0]
        continue
    s.append(1)
    t.append(1)
    remain.appendleft(now)
    lower1.append(left)
    continue

print(len(s))
print("".join(map(str, s)))
print("".join(map(str, t)))
