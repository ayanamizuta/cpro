a,b,c=map(int,input().split())
table = [
    [0],
    [1],
    [2,4,8,6],
    [3,9,7,1],
    [4,6],
    [5],
    [6],
    [7,9,3,1],
    [8,4,2,6],
    [9,1]
]
a = a%10
am = table[a]
al = len(am)
print(am[(pow(b,c,al)+al-1)%al])