import random as r
p=5
user=["aaaabbbbbb","AAAaaa","123123s","13Aaa","a#aa","!a","@@@@","\\aa",""]
domain=["ntnu.edu.tw","gapps.ntnu.edu.tw","csie.ntnu.edu.tw","csie.cool","gmail.com","gapps.ntnu.edu.twcsie.cool","gapps.ntnu.edu.twaaa","ntnugapps.ntnu.edu.tw"]
for i in range(0,2):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        f.write(user[r.randint(0,3)]+'@'+domain[r.randint(0,3)])
        f.write('\n')
        f.write('[hw'+str(r.randint(0,9))+'][p'+str(r.randint(0,9))+'] '+str(r.randint(0,999999999)))
        f.write('\n')
        f.write(str(r.randint(0,10**19)))
        f.write('\n')
for i in range(2,4):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        f.write(user[r.randint(0,3)]+'@'+domain[r.randint(0,3)])
        f.write('\n')
        f.write('[general] '+str(r.randint(0,999999999)))
        f.write('\n')
        f.write(str(r.randint(0,10**19)))
        f.write('\n')
for i in range(4,5):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        f.write(user[r.randint(0,8)]+'@'+domain[r.randint(0,7)])
        f.write('\n')
        f.write('[hw'+str(r.randint(0,9))+'][p'+str(r.randint(0,9))+'] '+str(r.randint(0,999999999)))
        f.write('\n')
        f.write(str(r.randint(0,10**19)))
        f.write('\n')
for i in range(5,7):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        f.write(user[r.randint(0,3)]+'@'+domain[r.randint(0,3)])
        f.write('\n')
        f.write('[hw'+str(r.randint(0,11))+'][p'+str(r.randint(0,11))+'] '+str(r.randint(0,999999999)))
        f.write('\n')
        f.write(str(r.randint(0,10**19)))
        f.write('\n')
for i in range(7,8):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        f.write(user[0]+'@'+domain[r.randint(0,3)])
        f.write('\n')
        f.write('[hw'+str(r.randint(0,11))+'][p'+str(r.randint(0,11))+'] '+str(r.randint(0,999999999)))
        f.write('\n')
        f.write(str(r.randint(0,10**11+5*(10**10))))
        f.write('\n')
for i in range(8,10):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        f.write(user[0]+'@'+domain[r.randint(0,3)])
        f.write('\n')
        f.write('[hw'+str(r.randint(0,11))+'][p'+str(r.randint(0,11))+'] '+str(r.randint(0,999999999)))
        f.write('\n')
        f.write(str(r.randint(0,10**20)))
        f.write('\n')