import sys
import random
from math import exp

def parse_answer(s):
    return int(s.split()[-1])

def sim_print():
    cheater = random.randint(0,100-1)
    s = [random.uniform(-3,3) for _ in range(100)]
    q = [random.uniform(-3,3) for _ in range(10000)]
    for i in range(100):
        if i == cheater:
            ret=""
            for j in range(10000):
                if random.random() < 0.5:# cheat
                    ret+="1"
                else:
                    ret+="1" if (random.random() < 1/(1+exp(q[j]-s[i]))) else "0"
            print(ret)
        else:
            ret=""
            for j in range(10000):
                ret+="1" if (random.random() < 1/(1+exp(q[j]-s[i]))) else "0"
            print(ret)

    return cheater+1

def validate_answer(cheater):
    cheater_estimated = parse_answer(input())
    return 1 if cheater==cheater_estimated else 0

def main():
    t = 50
    print(t)
    print(86)
    random.seed(42)
    acc = 0
    for _ in range(t):
        cheater=sim_print()
        acc+=validate_answer(cheater)
        print(acc,file=sys.stderr)
    print(f"accuracy {acc}/{t}",file=sys.stderr)


if __name__=="__main__":
    main()