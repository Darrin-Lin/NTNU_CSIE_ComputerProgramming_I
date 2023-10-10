import random as r
hw=2
hw_part=5
for i in range(0,4):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(3,10)))
        f.write('\n')
        f.write(str(r.randint(1,6)))
        f.write('\n')
for i in range(4,6):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(10,27)))
        f.write('\n')
        f.write("1")
        f.write('\n')
for i in range(6,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(3,7)))
        f.write('\n')
        f.write(str(r.randint(3,6)))
        f.write('\n')
for i in range(8,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-2,5)))
        f.write('\n')
        f.write(str(r.randint(-3,3)))
        f.write('\n')