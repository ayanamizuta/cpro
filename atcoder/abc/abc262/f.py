from re import L


n,k=map(int,input().split())
p=list(map(int,input().split()))
if not k:
    print(*p)
    exit()
l_min=min(p[:k+1])
r_min=min(p[-k:])
if l_min<r_min:
    ind_min = p.index(l_min)
    k-=ind_min
    p=p[ind_min:]
    while k:
        for i in range(len(p)):
            if i == len(p)-1:
                del p[-1]
                break
            if p[i]>p[i+1]:
                del p[i]
                break
        k-=1
elif l_min> r_min:
    ind_min=p.index(r_min)
    k_left = k - (n-ind_min)
    ind_min-=k_left
    k_right=k-k_left
    while k_left:
        for i in range(len(p)):
            if i == len(p)-1:
                del p[-1]
                break
            if p[i]>p[i+1]:
                del p[i]
                break
        k_left-=1
    prefix = [r_min]
    dp = [10**10]*k_right
    dp[-1]=p[-1]
    for i in range(2,k_right+1):
        dp[-i]=min(p[-i],dp[-i+1])
    for i in range(1,k_right):
        if prefix[-1]<dp[i]<p[0]:
            prefix.append(dp[i])
    p=prefix+p[:ind_min]
else:
    p_copy = [p_ for p_ in p]
    k_copy=k
    ind_min = p_copy.index(l_min)
    k_copy-=ind_min
    p_copy=p_copy[ind_min:]
    while k_copy:
        for i in range(len(p_copy)):
            if i == len(p_copy)-1:
                del p_copy[-1]
                break
            if p_copy[i]>p_copy[i+1]:
                del p_copy[i]
                break
        k_copy-=1

    ind_min=p.index(r_min)
    k_left = k - (n-ind_min)
    ind_min-=k_left
    k_right=k-k_left
    while k_left:
        for i in range(len(p)):
            if i == len(p)-1:
                del p[-1]
                break
            if p[i]>p[i+1]:
                del p[i]
                break
        k_left-=1
    prefix = [r_min]
    dp = [10**10]*k_right
    dp[-1]=p[-1]
    for i in range(2,k_right+1):
        dp[-i]=min(p[-i],dp[-i+1])
    for i in range(1,k_right):
        if prefix[-1]<dp[i]<p[0]:
            prefix.append(dp[i])
    p=prefix+p[:ind_min]
    if p > p_copy:
        p=p_copy
print(*p)