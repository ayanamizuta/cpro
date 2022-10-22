from math import exp,log
from scipy.stats import spearmanr
import sys

def solve_one(prob_num):
    a = [""]*100
    for i in range(100):
        a[i] = input()

    def est_s(i):
        r = a[i].count("1")/10000
        lhs = exp(6*(r-1))
        exp_minus_s = (1-lhs)/(exp(3)*lhs-exp(-3))
        return -log(exp_minus_s)

    s = [est_s(i) for i in range(100)]

    def est_q(j):
        lb=-3
        ub=3
        mean = sum([1 for i in range(100) if a[i][j]=="1"])
        while abs(ub-lb)>0.01:
            mid=(ub-lb)/2+lb
            if sum([1/(1+exp(mid-s[i])) for i in range(100)]) < mean:
                ub=mid
            else:
                lb=mid
        return lb

    q = [est_q(j) for j in range(10000)]

    corrs = [spearmanr([-int(x) for x in a[i]],q) for i in range(100)]
    minent = min(corrs)
    ret = corrs.index(minent)+1

    print(f"Case #{prob_num}: {ret}")

if __name__=="__main__":
    t = int(input())
    p = int(input())
    for i in range(t):
        solve_one(i+1)





