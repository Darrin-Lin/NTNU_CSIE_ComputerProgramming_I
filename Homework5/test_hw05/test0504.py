import random as r
hw=5
hw_part=4

length = 0
value = 0
tlv = list()
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


for i in range(0,10):
	with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
		for j in range(10):
			type = r.randint(0, 10)
			length,value = gen_tlv(type)
			tlv.append(type)
			tlv.append(length%10)
			tlv.append(length/10)
			for k in range(length):
				tlv.append(int(value / (10**(length-k-1))))
				value = value % (10**(length-k-1))
		f.write(str(len(tlv)+3)) #size
		for j in range(len(tlv)):
			f.write(str(tlv[j]))
			f.write(' ')
		f.write('\n')
		f.write("9 0 0")
		tlv.clear()
		f.write('\n')