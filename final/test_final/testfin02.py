import random as r
hw_part=2
for i in range(0,10):
    with open('./0'+str(hw_part)+'/in/fin'+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        for j in range(0,16):
            for k in range(0,30):
                f.write("-1 ")
            f.write('\n')
        f.write('\n')