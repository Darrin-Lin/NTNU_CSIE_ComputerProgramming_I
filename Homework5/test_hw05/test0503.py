import random as r
hw=5
hw_part=3
for i in range(0,1):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        f.write("5 0 0 2 4")
        f.write("\n")
for i in range(1,3):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        f.write(str(r.randint(1,20))+ " ")
        f.write(str(r.randint(1,20))+ " ")
        f.write(str(r.randint(1,20))+ " ")
        f.write(str(r.randint(1,20))+ " ")
        f.write(str(r.randint(1,20)))
        f.write("\n")

for i in range(3,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        f.write(str(r.random()*20)+ " ")
        f.write(str(r.random()*20)+ " ")
        f.write(str(r.random()*20)+ " ")
        f.write(str(r.random()*20)+ " ")
        f.write(str(r.random()*20))
        f.write("\n")
for i in range(5,6):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        f.write(str(r.random()*20)+ " ")
        f.write(str(r.randrange(-1,1,2)*r.random()*20)+ " ")
        f.write(str(r.randrange(-1,1,2)*r.random()*20)+ " ")
        f.write(str(r.randrange(-1,1,2)*r.random()*20)+ " ")
        f.write(str(r.randrange(-1,1,2)*r.random()*20))
        f.write("\n")
for i in range(6,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        f.write("1 0 0 0 0")
        f.write("\n")
for i in range(7,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        f.write("1 0 0 1 1")
        f.write("\n")
for i in range(8,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("0\n")
        f.write("0 0 0 0 0")
        f.write("\n")
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1")
        f.write("\n")