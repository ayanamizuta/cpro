s=input()
K_N=int(input())
MAX_K=500

I,J,K=s.count("K"),s.count("E"),s.count("Y")

dp=[[[[0 for _ in range(MAX_K+1)] for _ in range(K+1)] for _ in range(J+1)] for _ in range(I+1)] # dp[31][31][31][500]
dp[0][0][0][0]=1

k_acm=[0]*(len(s)+1)
for i in range(len(s)):
    k_acm[i+1]=k_acm[i]+(1 if s[i]=="K" else 0)
e_acm=[0]*(len(s)+1)
for i in range(len(s)):
    e_acm[i+1]=e_acm[i]+(1 if s[i]=="E" else 0)
y_acm=[0]*(len(s)+1)
for i in range(len(s)):
    y_acm[i+1]=y_acm[i]+(1 if s[i]=="Y" else 0)

i_indices = []
for i in range(len(s)):
    if s[i]=="K":
        i_indices.append(i)
j_indices = []
for i in range(len(s)):
    if s[i]=="E":
        j_indices.append(i)
k_indices = []
for i in range(len(s)):
    if s[i]=="Y":
        k_indices.append(i)

for i in range(I+1):
    for j in range(J+1):
        for k in range(K+1):
            for k_ in range(MAX_K):
                if i:
                    i_idx = i_indices[i-1]
                    e_n = e_acm[i_idx]
                    y_n = y_acm[i_idx]
                    k_cons = max(0,e_n-j) + max(0,y_n-k)
                    if MAX_K > k_cons+k_:
                        dp[i][j][k][k_cons+k_] += dp[i-1][j][k][k_]
                if j:
                    j_idx = j_indices[j-1]
                    k_n = k_acm[j_idx]
                    y_n = y_acm[j_idx]
                    k_cons = max(0,k_n-i) + max(0,y_n-k)
                    if MAX_K > k_cons+k_:
                        dp[i][j][k][k_cons+k_] += dp[i][j-1][k][k_]
                if k:
                    k_idx = k_indices[k-1]
                    k_n = k_acm[k_idx]
                    e_n = e_acm[k_idx]
                    k_cons = max(0,k_n-i) + max(0,e_n-j)
                    if MAX_K > k_cons+k_:
                        dp[i][j][k][k_cons+k_] += dp[i][j][k-1][k_]

print(sum(dp[I][J][K][:K_N+1]))