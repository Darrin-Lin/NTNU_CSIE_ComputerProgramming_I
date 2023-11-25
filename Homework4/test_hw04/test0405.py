import random as r
hw=4
hw_part=5
for i in range(0,1):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1 2 3 0\n0\n4 4 4 4 0\n1\n7 7 7 0\n0\n28 28 28 0\n1\n32 32\n28\n1\n0\n0")
        f.write('\n')
for i in range(1,2):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("34 34 34 0\n0\n33 33 33 0\n0\n28 28 28 0\n0\n9 9 9 0\n1\n32 32\n34\n0\n0\n0")
        f.write('\n')
for i in range(2,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1 9 32 10 18 19 27 29 30 31 33 34 28 32 0\n32\n0\n0\n0")
        f.write('\n')