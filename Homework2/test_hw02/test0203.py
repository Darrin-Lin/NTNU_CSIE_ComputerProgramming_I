import random as r
hw=2
hw_part=3
for i in range(0,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+'-'+str(i)+'.in', 'w') as f:
        for i in range(0,5):
            f.write(str(r.randint(1,100)))
            f.write('\n')
        f.write('0')
        f.write('\n')
for i in range(5,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+'-'+str(i)+'.in', 'w') as f:
        for i in range(0,r.randint(1,100)):
            f.write(str(r.randint(1,2<<10)))
            f.write('\n')
        f.write('0')
        f.write('\n')
for i in range(7,8):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+'-'+str(i)+'.in', 'w') as f:
        for i in range(0,r.randint(1,10)):
            f.write(str(r.randint(-100,-1)))
            f.write('\n')
        f.write('0')
        f.write('\n')
for i in range(7,9):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+'-'+str(i)+'.in', 'w') as f:
        for i in range(0,r.randint(1,1000)):
            f.write(str(r.randint(-1*(2<<16),(2<<16)-1)))
            f.write('\n')
        f.write('0')
        f.write('\n')
for i in range(9,10):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+'-'+str(i)+'.in', 'w') as f:
		f.write('0')
		f.write('\n')