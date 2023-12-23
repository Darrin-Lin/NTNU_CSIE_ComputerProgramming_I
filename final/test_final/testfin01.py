import random as r
hw_part=1
for i in range(0,8):
    with open('./0'+str(hw_part)+'/in/fin'+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        #four inputs
        f.write(str(r.randint(1,100))+ ' ' + str(r.randint(1,100)) + ' ' + str(r.randint(1,100)) +' '+ str(r.randint(1,100)))
        f.write('\n')

for i in range(8,9):
    with open('./0'+str(hw_part)+'/in/fin'+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1 0 1 0")
        f.write('\n')
for i in range(9,10):
    with open('./0'+str(hw_part)+'/in/fin'+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1 1 0 1")
        f.write('\n')