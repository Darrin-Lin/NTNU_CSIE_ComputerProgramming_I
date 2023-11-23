import random as r
hw=4
hw_part=5
for i in range(0,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1 2 3 0\n0\n4 4 4 4 0\n1\n7 7 7 0\n0\n28 28 28 0\n1\n32 32\n28\n1\n0\n0")
        f.write('\n')