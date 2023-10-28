import random as r
hw=3
hw_part=1
for i in range(0,6):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1")
        f.write('\n')
        radius=r.random()*r.randint(1, 100)
        f.write(str(radius))
        f.write('\n')
        for j in range(0, 10):
            act=r.randint(1, 6)
            f.write(str(act))
            f.write('\n')
            if act==1:
                radius=r.random()*r.randint(1, 100)
                f.write(str(radius))
                f.write('\n')
            elif act==4:
                f.write(str(radius*r.random()*r.randrange(-1,2,2)))
                f.write('\n')
            elif act==5:
                f.write(str(r.randint(3, 15)))
                f.write('\n')
            elif act==6:
                f.write(str(r.randint(3, 15)))
                f.write('\n')
        f.write('0')
        f.write('\n')
for i in range(6,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1")
        f.write('\n')
        radius=r.random()*r.randint(1, 100)
        f.write(str(radius))
        f.write('\n')
        f.write("1")
        f.write('\n')
        f.write(str(-1 *r.randint(1, 100)))
        f.write('\n')
        for j in range(2,7):
            f.write(str(j))
            f.write('\n')
            if j==4:
                f.write(str(radius*r.random()*r.randrange(-1,2,2)))
                f.write('\n')
            elif j==5:
                f.write(str(r.randint(3, 15)))
                f.write('\n')
            elif j==6:
                f.write(str(r.randint(3, 15)))
                f.write('\n')
        f.write('\n')
        
        f.write('0')
        f.write('\n')
for i in range(7,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        for j in range(2,7):
            f.write(str(j))
            f.write('\n')
            if act==4:
                f.write(str(radius*r.random()*r.randrange(-1,2,2)))
                f.write('\n')
            elif act==5:
                f.write(str(r.randint(3, 15)))
                f.write('\n')
            elif act==6:
                f.write(str(r.randint(3, 15)))
                f.write('\n')
        f.write('0')
        f.write('\n')
for i in range(8,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1")
        f.write('\n')
        f.write(str(-1 *r.randint(1, 100)))
        f.write('\n')
        for j in range(2,7):
            f.write(str(j))
            f.write('\n')
        f.write('\n')
        if act==4:
            f.write(str(radius*r.random()*r.randrange(-1,2,2)))
            f.write('\n')
        elif act==5:
            f.write(str(r.randint(3, 15)))
            f.write('\n')
        elif act==6:
            f.write(str(r.randint(3, 15)))
            f.write('\n')
        f.write('0')
        f.write('\n')
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1")
        f.write('\n')
        radius=r.randint(1, 100)
        f.write(str(radius))
        f.write('\n')
        f.write("4")
        f.write(str(radius*r.randrange(-1,2,2)))
        f.write('\n')
        f.write("4")
        f.write("0")
        f.write('\n')
        for j in range(0,5):
            f.write("5")
            f.write(str(r.randint(-3, 2)))
            f.write('\n')
            f.write("6")
            f.write(str(r.randint(-3, 2)))
            f.write('\n')
        f.write('0')
        f.write('\n')