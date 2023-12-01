import random as r
hw=5
hw_part=1
for i in range(0,3):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        size=r.randint(5,10)
        f.write(str(size))
        f.write('\n')
        for j in range(0,size):
            f.write(str(r.randint(1,100))+" ")
        f.write('\n')
for i in range(3,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        size=r.randint(10,1000)
        f.write(str(size))
        f.write('\n')
        for j in range(0,size):
            f.write(str(r.randint(-100,100))+" ")
        f.write('\n')
for i in range(5,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        size=r.randint(1000,100000)
        f.write(str(size))
        f.write('\n')
        for j in range(0,size):
            f.write(str(r.randint(-10000,10000))+" ")
        f.write('\n')
for i in range(7,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        size=r.randint(100000,1000000)
        f.write(str(size))
        f.write('\n')
        for j in range(0,size):
            f.write(str(r.randint(-100000,100000))+" ")
        f.write('\n')
for i in range(8,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("-1\n")
        f.write('\n')
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1\n")
        f.write('\n')