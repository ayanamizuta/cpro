
lu_ = [[1e9 for _ in range(120)] for _ in range(120)]
ld_ = [[1e9 for _ in range(120)] for _ in range(120)]
ru_ = [[1e9 for _ in range(120)] for _ in range(120)]
rd_ = [[1e9 for _ in range(120)] for _ in range(120)]

table = [lu_,ld_,ru_,rd_,lu_,ld_,ru_,rd_]

offset = 50
def os(i):
    return i + offset
ld_[os(0)][os(0)] = 0
for ii in range(10):
    for i in range(-20,20):
        for j in range(-20,20):
            lu = table[0]
            ld = table[1]
            ru = table[2]
            rd = table[3]
            if os(i+1) < 120 and os(j+1) < 120:
                ru[os(i+1)][os(j+1)] = min(ld[os(i)][os(j)]+1,ru[os(i+1)][os(j+1)])
            if os(i+1) < 120 and os(j) < 120:
                ru[os(i+1)][os(j)] = min(ld[os(i)][os(j)]+1,ru[os(i+1)][os(j)])
            if os(i) < 120 and os(j+1) < 120:
                ru[os(i)][os(j+1)] = min(ld[os(i)][os(j)]+1,ru[os(i)][os(j+1)])

            if os(i) < 120 and os(j) < 120:
                rd[os(i)][os(j)] = min(ld[os(i)][os(j)]+1,rd[os(i)][os(j)])
            if os(i+1) < 120 and os(j) < 120:
                rd[os(i+1)][os(j)] = min(ld[os(i)][os(j)]+1,rd[os(i+1)][os(j)])

            if os(i) < 120 and os(j) < 120:
                lu[os(i)][os(j)] = min(ld[os(i)][os(j)]+1,lu[os(i)][os(j)])
            if os(i) < 120 and os(j+1) < 120:
                lu[os(i)][os(j+1)] = min(ld[os(i)][os(j)]+1,lu[os(i)][os(j+1)])

            ##
            if os(i+1) < 120 and os(j-1) < 120 and os(j-1) >= 0:
                rd[os(i+1)][os(j-1)] = min(lu[os(i)][os(j)]+1,rd[os(i+1)][os(j-1)])
            if os(i+1) < 120 and os(j) < 120:
                rd[os(i+1)][os(j)] = min(lu[os(i)][os(j)]+1,rd[os(i+1)][os(j)])
            if os(i) < 120 and os(j-1) < 120 and os(j-1) >= 0:
                rd[os(i)][os(j-1)] = min(lu[os(i)][os(j)]+1,rd[os(i)][os(j-1)])

            if os(i) < 120 and os(j) < 120:
                ld[os(i)][os(j)] = min(lu[os(i)][os(j)]+1,ld[os(i)][os(j)])
            if os(i) < 120 and os(j-1) < 120 and os(j-1) >= 0:
                ld[os(i)][os(j-1)] = min(lu[os(i)][os(j)]+1,ld[os(i)][os(j-1)])

            if os(i) < 120 and os(j) < 120:
                ru[os(i)][os(j)] = min(lu[os(i)][os(j)]+1,ru[os(i)][os(j)])
            if os(i+1) < 120 and os(j) < 120:
                ru[os(i+1)][os(j)] = min(lu[os(i)][os(j)]+1,ru[os(i+1)][os(j)])

            ##
            if os(i-1) >= 0 and os(j+1) < 120:
                lu[os(i-1)][os(j+1)] = min(rd[os(i)][os(j)]+1,lu[os(i-1)][os(j+1)])
            if os(i-1) >= 0 and os(j) < 120:
                lu[os(i-1)][os(j)] = min(rd[os(i)][os(j)]+1,lu[os(i-1)][os(j)])
            if os(i) < 120 and os(j+1) < 120:
                lu[os(i)][os(j+1)] = min(rd[os(i)][os(j)]+1,lu[os(i)][os(j+1)])

            if os(i) < 120 and os(j) < 120:
                ld[os(i)][os(j)] = min(rd[os(i)][os(j)]+1,ld[os(i)][os(j)])
            if os(i-1) >= 0 and os(j) < 120:
                ld[os(i-1)][os(j)] = min(rd[os(i)][os(j)]+1,ld[os(i-1)][os(j)])

            if os(i) < 120 and os(j) < 120:
                ru[os(i)][os(j)] = min(rd[os(i)][os(j)]+1,ru[os(i)][os(j)])
            if os(i) < 120 and os(j+1) < 120:
                ru[os(i)][os(j+1)] = min(rd[os(i)][os(j)]+1,ru[os(i)][os(j+1)])

            ## 
            if os(i-1) >= 0 and os(j-1) >= 0:
                ld[os(i-1)][os(j-1)] = min(ru[os(i)][os(j)]+1,ld[os(i-1)][os(j-1)])
            if os(i-1) >= 0 and os(j) >= 0:
                ld[os(i-1)][os(j)] = min(ru[os(i)][os(j)]+1,ld[os(i-1)][os(j)])
            if os(i) >= 0 and os(j-1) >= 0:
                ld[os(i)][os(j-1)] = min(ru[os(i)][os(j)]+1,ld[os(i)][os(j-1)])

            if os(i) < 120 and os(j) < 120:
                lu[os(i)][os(j)] = min(ru[os(i)][os(j)]+1,lu[os(i)][os(j)])
            if os(i-1) < 120 and os(j) >= 0:
                lu[os(i-1)][os(j)] = min(ru[os(i)][os(j)]+1,lu[os(i-1)][os(j)])

            if os(i) < 120 and os(j) < 120:
                rd[os(i)][os(j)] = min(ru[os(i)][os(j)]+1,rd[os(i)][os(j)])
            if os(i) < 120 and os(j-1) < 120:
                rd[os(i)][os(j-1)] = min(ru[os(i)][os(j)]+1,rd[os(i)][os(j-1)])



lu = [x[os(0)-5:os(0)+5] for x in lu_[os(0)-5:os(0)+5]]
ld = [x[os(0)-5:os(0)+5] for x in ld_[os(0)-5:os(0)+5]]
ru = [x[os(0)-5:os(0)+5] for x in ru_[os(0)-5:os(0)+5]]
rd = [x[os(0)-5:os(0)+5] for x in rd_[os(0)-5:os(0)+5]]

print("lu")
for l in lu:
    print(l)

print("ld")
for l in ld:
    print(l)

print("ru")
for l in ru:
    print(l)

print("rd")
for l in rd:
    print(l)