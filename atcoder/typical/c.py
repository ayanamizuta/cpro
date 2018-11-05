n=int(input())

l=1
while l <= 2*n+1:
    l*=2

a=[0]*l
b=[0]*l

for i in range(n):
    a[i+1],b[i+1]=list(map(int,input().split(' ')))

import numpy as np

c=np.fft.fft(a)
d=np.fft.fft(b)

e=c*d

f=np.fft.ifft(e)


for i in range(1,2*n+1):
    print(int(np.real(f[i])+0.1))
