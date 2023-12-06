import random as r
hw=5
hw_part=4

length = 0
value = 0

def gen_tlv(t):
	if((t >= 1 and t <= 3) or (t >= 6 and t <= 7)):
		leng = r.randint(1, 99)
		val = r.randint(10**leng, 10**(leng+1)-1)
	elif((t >= 4 and t <= 5) or (t >= 8 and t <= 10)):
		leng = 0
		val = 0 #no need to use
	else:
		leng = 0
		val = 0 #no need to use
	return leng, val


for i in range(0,1):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
		f.write("10\n")
		f.write("0 0 0\n")
		f.write("1 1 0 1\n")
		f.write("9 0 0\n")
for i in range(1,2):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
		f.write("327\n")#48+256+23=327
		f.write("0 0 0\n")
		f.write("0 0 1")
		for j in range(256):
			f.write(' '+str(r.randint(0, 9)))
		f.write('\n')
		f.write("1 1 0 9\n")
		f.write("9 0 0\n")
		f.write("2 2 0 9 9\n")
		f.write("9 0 0\n")
		f.write("3 3 0 20\n")
		f.write("9 0 0\n")
		f.write("4 0 0\n")
		f.write("9 0 0\n")
		f.write("5 0 0\n")
		f.write("9 0 0\n")
		f.write("6 2 0 1 2\n")
		f.write("9 0 0\n")
		f.write("7 2 0 3 4\n")
		f.write("9 0 0\n")
		f.write("8 0 0\n")
		f.write("10 0 0\n")
		f.write("9 0 0\n")
		f.write("9 0 0\n")
		f.write("10 0 0\n")

for i in range(2,3):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
		f.write("19\n")
		f.write("10 0 0\n")
		f.write("10 0 0\n")
		f.write("10 0 0\n")
		f.write("10 0 0\n")
		f.write("1 1 0 1\n")
		f.write("9 0 0\n")
for i in range(3,7):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
		tlv = list()
		for j in range(10):
			type = r.randint(0, 10)
			length,value = gen_tlv(type)
			tlv.append(type)
			tlv.append(length%256)
			tlv.append(length/256)
			for k in range(length):
				tlv.append(int(value / (10**(length-k-1))))
				value = value % (10**(length-k-1))
		f.write(str(len(tlv)+3)) #size
		f.write('\n')
		for j in range(len(tlv)):
			f.write(str(tlv[j]))
			f.write(' ')
		f.write('\n')
		f.write("9 0 0")
		# tlv.clear()
		f.write('\n')

for i in range(7,8):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
		f.write("10\n")
		f.write("0 0 0\n")
		f.write("10 1 0 1\n")
		f.write("9 0 0\n")

for i in range(8,9):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
		f.write("12\n")
		f.write("10 0 0\n")
		f.write("9 0 0\n")
		f.write("8 0 0\n")
		f.write("9 0 0\n")

for i in range(9,10):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
		f.write("9\n")
		f.write("8 0 0\n")
		f.write("10 0 0\n")
		f.write("2 0 1\n")
		