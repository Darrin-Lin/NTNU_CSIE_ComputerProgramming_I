import random as r
hw=3
hw_part=3
for i in range(0,1):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write('0')
        f.write('\n')
for i in range(1,4):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(1,255)))
        f.write('\n')
for i in range(4,6):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-65536,65535)))
        f.write('\n')
for i in range(6,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-1*(2<<31),(2<<31)-1)))
        f.write('\n')
for i in range(8,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-1*(2<<63),(2<<63)-1)))
        f.write('\n')
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1a1")
        f.write('\n')