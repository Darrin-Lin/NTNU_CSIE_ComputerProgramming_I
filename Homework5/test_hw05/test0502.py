import random as r
hw=5
hw_part=2

def generate_matrix(n,rang):
     
#     matrix[n][n]
    f.write(str(n))
    f.write('\n')
    x=list()
    y=list()
    for i in range(0,n):
        x.append(r.randint(1,rang)*r.randrange(-1,2,2))
    for i in range(0,n):
        m=list()
        tem=0
        for j in range(0,n):
            m.append(r.randint(1,rang)*r.randrange(-1,2,2))
            f.write(str(m[j])+' ')
            tem+=(x[j]*m[j])
        y.append(tem)
        f.write('\n')
    for i in range(0,n):
        f.write(str(y[i])+' ')
        print(str(x[i])+' ',end='')
    print('\n')
    f.write('\n')
    

for i in range(0,1):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        # f.write("3\n")
        generate_matrix(3,10)
        f.write('\n')
for i in range(1,4):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        n=r.randint(2,5)
        generate_matrix(n,10)
        # f.write(str(n)+"\n")
        # for j in range(n):
        #     for k in range(n):
        #         f.write(str(r.randint(-20,20))+" ")
        #     f.write("\n")
        # f.write("\n")
        # for j in range(n):
        #     f.write(str(r.randint(-20,20))+" ")
        # f.write("\n")
for i in range(4,6):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        n=r.randint(5,10)
        generate_matrix(n,100)
        # f.write(str(n)+"\n")
        # for j in range(n):
        #     for k in range(n):
        #         f.write(str(r.randint(-100,100))+" ")
        #     f.write("\n")
        # f.write("\n")
        # for j in range(n):
        #     f.write(str(r.randint(-100,100))+" ")
        # f.write("\n")
for i in range(6,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        n=r.randint(10,100)
        generate_matrix(n,1000)
        # f.write(str(n)+"\n")
        # for j in range(n):
        #     for k in range(n):
        #         f.write(str(r.randint(-1000,1000))+" ")
        #     f.write("\n")
        # f.write("\n")
        # for j in range(n):
        #     f.write(str(r.randint(-1000,1000))+" ")
        # f.write("\n")
for i in range(8,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1")
        f.write("\n")
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("-1")
        f.write("\n")