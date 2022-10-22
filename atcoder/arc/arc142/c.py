n=int(input())
dic = {}
dic2= {}
def print_query(u,v):
    print(f"? {u} {v}")
def print_answer(d):
    print(f"! {d}")

for i in range(3,n+1):
    print_query(1,i)
    d = int(input())
    dic[(1,i)]=d

if not any(v == 1 for v in dic.values()):
    print_answer(1)
    exit()

k=None
for k_ in dic.keys():
    if dic[k_]==1:
        k=k_[1]
        break

for i in range(3,n+1):
    print_query(2,i)
    d = int(input())
    dic2[(2,i)]=d

if dic2[(2,k)]==1:
    print_answer(2)
    exit()

if not any(v == 1 for v in dic2.values()):
    print_answer(1)
    exit()

k2=None
for k_ in dic2.keys():
    if dic2[k_]==1:
        k2=k_[1]
        break

print_query(k,k2)
d=int(input())

if d > dic[(1,k2)]:
    print_answer(dic2[(2,k)]-1)
else:
    print_answer(dic2[(2,k)]+1)