import random as r
p=4

for i in range(0,8):
	card=list()
	for j in range(1,53):
		card.append(j)
	
	with open('./0'+str(p)+'/in/hw010'+str(p)+"_0"+str(i)+'.in', 'w') as f:
		for j in range(0,13):
			f.write(str(card.pop(r.randint(0,51-j))))
			f.write('\n')
for i in range(8,10):
	with open('./0'+str(p)+'/in/hw010'+str(p)+"_0"+str(i)+'.in', 'w') as f:
		for j in range(0,13):
			f.write(str(r.randint(-100,100)))
			f.write('\n')