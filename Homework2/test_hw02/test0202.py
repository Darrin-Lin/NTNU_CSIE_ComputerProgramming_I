import random as r
hw=2
hw_part=2
for i in range(0,3):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(1,100)))
        f.write('\n')
        f.write(str(r.randint(1,100)))
        f.write('\n')
for i in range(3,4):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write('0')
        f.write('\n')
        f.write(str(r.randint(1,10000)))
        f.write('\n')
for i in range(4,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write('0')
        f.write('\n')
        f.write(str(r.randint(1,10000)))
        f.write('\n')
for i in range(5,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(1,(1<<31)-1)))
        f.write('\n')
        f.write(str(r.randint(1,(1<<31)-1)))
        f.write('\n')
for i in range(8,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-(1<<31),-1)))
        f.write('\n')
        f.write(str(r.randint(-(1<<31),-1)))
        f.write('\n')