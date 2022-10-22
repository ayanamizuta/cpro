n=int(input())
s=input()
t=input()
arr = [None]*n
cnt_diff=0
for i in range(n):
    if s[i]!=t[i]:
        cnt_diff+=1
if cnt_diff%2:
    print(-1)
    exit()
ham_s=0
ham_t=0
for i in range(n):
    if s[i]==t[i]:
        arr[i]="0"
    else:
        if s[i]=="0":
            if ham_t>=cnt_diff//2:
                arr[i]="1"
                ham_s+=1
            else:
                arr[i]="0"
                ham_t+=1
        else:
            if ham_s>=cnt_diff//2:
                arr[i]="1"
                ham_t+=1
            else:
                arr[i]="0"
                ham_s+=1

print("".join(arr))
