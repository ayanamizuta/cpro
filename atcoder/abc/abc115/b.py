n=int(input())
p = [0]*n
for i in range(n):
    p[i] = int(input())
print(sum(p)-max(p)//2)
