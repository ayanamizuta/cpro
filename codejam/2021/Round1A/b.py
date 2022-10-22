t = int(input())

def flip(s):
    return "".join(map(lambda x: return "T" if x=="F" else "F",s))

def solve_one(pn):
    n,q = map(int,input().split())
    s = []
    scores = []
    for _ in range(n):
        s_in,score_in = input().split()
        s.append(s_in)
        scores.append(int(score_in))
    if n == 1:
        if scores[0] > q/2:
            print(f"Case #{pn}: {s[0]} {scores[0]}/1")
        else:
            print(f"Case #{pn}: {flip(s[0])} {q-scores[0]}/1")
        return

    if n == 2:
        share=0
        not_share=0
        for i in range(q):
            if s[0][i] == s[1][i]:
                share+=1
            else:
                not_share+=1

        denom = [0]*41
        fill_prob_2(denom)

        max_score=0
        max_score_str=""
        for share_same in [False,True]:
            for follow_index in [0,1]:
                score_cand=0

                if max_score < score_cand:
                    max_score=score_cand
                    max_score_str=str_prod_2(share_same,follow_index,follow=True)

        for share_same in [False,True]:
            for disfollow_index in [0,1]:

        from math import gcd
        gcd_ = gcd(max_score,sum(denom))

        print(f"Case #{pn}: {max_score_str} {max_score//gcd_}/{sum(denom)//gcd_}")
        return 
        
    # verdict 3
    ret = 0 
    for i in range(n-1):
        ret += inc(i,l)
    print(f"Case #{pn}: {ret}")

for i in range(t):
    solve_one(i+1) 