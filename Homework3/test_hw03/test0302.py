import random as r
import math as m
hw=3
hw_part=2
for i in range(0,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1")
        f.write('\n')
        f.write(str(r.random()*r.randint(1, 100))+" "+str(r.random()*r.randint(1, 100))+" "+str(r.random()*2*m.pi))
        f.write('\n')
        for j in range(0, 10):
            act=r.randint(1, 4)
            f.write(str(act))
            f.write('\n')
            if act==1:
                f.write(str(r.random()*r.randint(1, 100))+" "+str(r.random()*r.randint(1, 100))+" "+str(r.random()*2*m.pi))
                f.write('\n')
            elif act==2:
                f.write(str(r.random()*r.randint(1, 100)))
                f.write('\n')
            elif act==3:
                f.write(str(r.random()*2*m.pi))
                f.write('\n')
            elif act==4:
                f.write(str(r.random()*2*m.pi))
                f.write('\n')
            f.write("5")
            f.write('\n')
        f.write('0')
        f.write('\n')
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        for j in range(2,6):
            f.write(str(j))
            f.write('\n')
            if j==2:
                f.write(str(r.random()*r.randint(1, 100)))
                f.write('\n')
            elif j==3:
                f.write(str(r.random()*2*m.pi))
                f.write('\n')
            elif j==4:
                f.write(str(r.random()*2*m.pi))
                f.write('\n')
            f.write('0')
            f.write('\n')