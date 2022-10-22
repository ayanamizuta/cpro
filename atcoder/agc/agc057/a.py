t=int(input())



def solve():
    l,r=map(int,input().split())
    digit_r = len(str(r))
    digit_l = len(str(l))
    if digit_l==digit_r:
        print(r-l+1)
        return
    num_longest_digit = r - 10**(digit_r-1)+1
    if digit_l==digit_r-1:
        if num_longest_digit >= 10**(digit_r-1):
            print(num_longest_digit)
        else:
            print(min(r-l+1,r-(max(r//10,r-10**(digit_r-1)))))
        return
    num_second_longest_digit = 10**(digit_r-1)-1 - 10**(digit_r-2)+1
    print(max([num_longest_digit,num_second_longest_digit,r-(max(r//10,r-10**(digit_r-1)))]))

for _ in range(t):
    solve()