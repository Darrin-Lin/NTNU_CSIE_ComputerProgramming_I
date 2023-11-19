import random as r
hw=4
hw_part=2
for i in range(0,4):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=r.randint(1,5)
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,10)))
        f.write(' ')
        for j in range(n):
            f.write(str(r.randint(0,9)))
            f.write(' ')
        f.write('\n')
        n=r.randint(1,5)
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,10)))
        f.write(' ')
        for j in range(n):
            f.write(str(r.randint(0,9)))
            f.write(' ')
        f.write('\n')
for i in range(3,4):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n2\n2\n1 0 0\n")
for i in range(4,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=0
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,100)))
        f.write('\n')
        n=r.randint(1,10)
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,100)))
        f.write(' ')
        for j in range(n):
            f.write(str(r.randint(0,99)))
            f.write(' ')
        f.write('\n')
for i in range(5,6):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=r.randint(1,10)
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,100)))
        f.write(' ')
        for j in range(n):
            f.write(str(r.randint(0,99)))
            f.write(' ')
        f.write('\n')
        n=0
        f.write(str(n))
        f.write('\n')
        f.write('0')
        
        f.write('\n')
for i in range(6,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=r.randint(1,10)
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,100)))
        f.write(' ')
        for j in range(n):
            f.write(str(r.randint(0,99)))
            f.write(' ')
        f.write('\n')
        n=r.randint(1,10)
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,100)))
        f.write(' ')
        for j in range(n):
            f.write(str(r.randint(0,99)))
            f.write(' ')
        f.write('\n')
for i in range(7,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=r.randint(1,10)
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,100)))
        f.write(' ')
        for j in range(n+1):
            f.write(str(r.randint(0,99)))
            f.write(' ')
        f.write('\n')
        n=r.randint(1,10)
        f.write(str(n))
        f.write('\n')
        f.write(str(r.randint(1,100)))
        f.write(' ')
        for j in range(n):
            f.write(str(r.randint(0,99)))
            f.write(' ')
        f.write('\n')
for i in range(8,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=1<<33
        f.write(str(n))
        f.write('\n')
        
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        n=1
        f.write(str(n))
        f.write('\n')
        f.write("1 ")
        f.write(str(r.choice([-1,1,2])*1<<33))
        f.write('\n')
        n=1
        f.write(str(n))
        f.write('\n')
        f.write("1 ")
        f.write(str(r.choice([-1,1,2])*1<<33))
        f.write('\n')

