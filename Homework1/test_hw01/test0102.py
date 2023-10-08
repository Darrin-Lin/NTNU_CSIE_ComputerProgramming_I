import random as r
for i in range(0,8):
    with open('./02/in/hw0102_0'+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(1,99)))
        f.write('\n')
        f.write(str(r.randint(1,99)))
        f.write('\n')
for i in range(8,10):
    with open('./02/in/hw0102_0'+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-1000,1000)))
        f.write('\n')
        f.write(str(r.randint(-1000,1000)))
        f.write('\n')