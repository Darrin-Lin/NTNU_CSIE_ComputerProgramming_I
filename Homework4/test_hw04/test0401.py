import random as r
hw=4
hw_part=1
for i in range(0,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=r.randint(1,100)
        f.write(str(n))
        f.write('\n')
        for j in range(n):
            f.write(str(r.randint(1,1000)))
            f.write(' ')
        f.write('\n')
for i in range(5,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=r.randint(1,1000)
        f.write(str(n))
        f.write('\n')
        for j in range(n):
            f.write(str(r.randint(1,10000)))
            f.write(' ')
        f.write('\n')
for i in range(8,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=r.randint(1,10000)
        f.write(str(n))
        f.write('\n')
        for j in range(n):
            f.write(str(r.randint(1,100000)))
            f.write(' ')
        f.write('\n')