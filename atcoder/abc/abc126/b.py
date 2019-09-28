s=input()
fst,snd=s[:2],s[2:]
def m(s_):
    if int(s_) <= 12 and int(s_) > 0:
        return True
    return False

if m(fst) and m(snd):
    print("AMBIGUOUS")
elif m(fst):
    print("MMYY")
elif m(snd):
    print("YYMM")
else:
    print("NA")
