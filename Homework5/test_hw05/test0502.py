import random as r
hw=5
hw_part=2

# def generate_matrix(n,rang):
#     matrix[n][n]
#     x=list()
#     for i in range(0,n):
#         x.append(r.randint(1,rang))
        

for i in range(0,1):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        f.write("3\n")
        f.write("1 -2 -1\n")
        f.write("-2 4 2\n")
        f.write("3 -6 -3\n")
        f.write("\n")
        f.write("3 -6 9")
        f.write('\n')
for i in range(1,4):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        n=r.randint(2,5)
        f.write(str(n)+"\n")
        for j in range(n):
            for k in range(n):
                f.write(str(r.randint(-20,20))+" ")
            f.write("\n")
        f.write("\n")
        for j in range(n):
            f.write(str(r.randint(-20,20))+" ")
        f.write("\n")
for i in range(4,6):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        n=r.randint(5,10)
        f.write(str(n)+"\n")
        for j in range(n):
            for k in range(n):
                f.write(str(r.randint(-100,100))+" ")
            f.write("\n")
        f.write("\n")
        for j in range(n):
            f.write(str(r.randint(-100,100))+" ")
        f.write("\n")
for i in range(6,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        n=r.randint(10,100)
        f.write(str(n)+"\n")
        for j in range(n):
            for k in range(n):
                f.write(str(r.randint(-1000,1000))+" ")
            f.write("\n")
        f.write("\n")
        for j in range(n):
            f.write(str(r.randint(-1000,1000))+" ")
        f.write("\n")
for i in range(8,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1")
        f.write("\n")
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("-1")
        f.write("\n")