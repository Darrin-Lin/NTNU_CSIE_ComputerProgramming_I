import random as r
hw=5
hw_part=5
for i in range(0,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1\n")
        f.write(str(r.randint(0,255)))
        f.write('\n')
        start=r.randint(0,100)
        end=r.randint(start,200)
        f.write(str(start))
        f.write('\n')
        f.write(str(end))
        f.write('\n')
        f.write(str(r.randint(0,255)))
        f.write('\n')
        start=r.randint(0,100)
        end=r.randint(start,200)
        f.write(str(start))
        f.write('\n')
        f.write(str(end))
        f.write('\n')
for i in range(5,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        time = r.randint(5,10)
        f.write(str(time)+'\n')
        for i in range(time):
            f.write(str(r.randint(0,255)))
            f.write('\n')
            start=r.randint(0,1000)
            end=r.randint(start,5000)
            f.write(str(start))
            f.write('\n')
            f.write(str(end))
            f.write('\n')
            f.write(str(r.randint(0,1000)))
            f.write('\n')
            start=r.randint(0,1000)
            end=r.randint(start,2000)
            f.write(str(start))
            f.write('\n')
            f.write(str(end))
            f.write('\n')
for i in range(7,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        time = r.randint(10,100)
        f.write(str(time)+'\n')
        for i in range(time):
            f.write(str(r.randint(0,255)))
            f.write('\n')
            start=r.randint(0,1000)
            end=r.randint(start,5000)
            f.write(str(start))
            f.write('\n')
            f.write(str(end))
            f.write('\n')
            f.write(str(r.randint(0,1000)))
            f.write('\n')
            start=r.randint(0,1000)
            end=r.randint(start,2000)
            f.write(str(start))
            f.write('\n')
            f.write(str(end))
            f.write('\n')