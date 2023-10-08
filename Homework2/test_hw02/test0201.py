import random as r
hw=2
hw_part=1
for i in range(0,3):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(1,10)))
        f.write('\n')
for i in range(3,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(0,1000)))
        f.write('\n')
for i in range(5,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(0,(1<<16)-1)))
        f.write('\n')
for i in range(7,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(0))
        f.write('\n')
for i in range(8,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-1*(1<<16),(1<<16)-1)))
        f.write('\n')