import random as r
hw=4
hw_part=5
for i in range(0,1):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("34 34 34 0\n0\n33 33 33 0\n0\n28 28 28 0\n0\n9 9 9 0\n1\n32 32\n34\n0\n0")
        f.write('\n')
for i in range(1,2):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1 9 32 10 18 19 27 29 30 31 33 34 28 32 0\n32\n0\n0")
        f.write('\n')
for i in range(2,3):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("1 2 3 0\n0\n4 4 4 4 0\n1\n7 7 7 0\n0\n28 28 28 0\n0\n32 32\n28\n0\n0")
        f.write('\n')
for i in range(3,4): # Seven pairs
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("19 19 20 20 3 3 4 4 6 6 16 16 31 31 0\n31\n0\n0")
        f.write('\n')
for i in range(4,5): # No-point hand
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("19 20 21 0\n0\n23 24 25 0\n0\n2 3 4 0\n0\n14 15 16 0\n0\n18 18\n14\n0\n0")
        f.write('\n')
for i in range(5,6): # One set of identical sequences
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("19 20 21 0\n0\n19 20 21 0\n0\n13 13 13 0\n0\n16 17 18 0\n0\n12 12\n12\n0\n0")
        f.write('\n')
for i in range(6,7): # Three colour straights
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("19 20 21 0\n0\n1 2 3 0\n0\n10 11 12 0\n0\n15 15 15 0\n0\n30 30\n12\n0\n0")
        f.write('\n')
for i in range(7,8): # Straight
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("19 20 21 0\n0\n22 23 24 0\n0\n25 26 27 0\n0\n1 1 1 0\n0\n28 28\n28\n0\n0")
        f.write('\n')
for i in range(8,9): # Two sets of identical sequences
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("10 11 12 0\n0\n10 11 12 0\n0\n2 3 4 0\n0\n2 3 4 0\n0\n28 28\n28\n0\n0")
        f.write('\n')
for i in range(9,10): # All triplets 
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("21 21 21 0\n1\n4 4 4 0\n0\n12 12 12 0\n0\n28 28 28 0\n0\n29 29\n29\n0\n0")
        f.write('\n')
for i in range(10,11): # Three concealed triplets
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 0\n0\n1 1 1 0\n0\n10 10 10 0\n0\n12 13 14 0\n0\n28 28\n28\n0\n0")
        f.write('\n')
for i in range(11,12): # Three colour triplets
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("21 21 21 0\n0\n3 3 3 0\n0\n12 12 12 0\n0\n14 15 16 0\n0\n34 34\n34\n0\n0")
        f.write('\n')
for i in range(12,13): # Three kans
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("14 15 16 0\n0\n21 21 21 21 0\n1\n3 3 3 3 0\n1\n12 12 12 12 0\n1\n34 34\n34\n0\n0")
        f.write('\n')
for i in range(13,14): # All simples
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("20 21 22 0\n0\n23 24 25 0\n0\n3 3 3 0\n0\n13 14 15 0\n0\n17 17\n17\n0\n0")
        f.write('\n')
for i in range(14,15): # Terminal or honor in each set 
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 20 21 0\n0\n25 26 27 0\n0\n1 2 3 0\n0\n28 28 28 0\n0\n33 33\n33\n0\n0")
        f.write('\n')
for i in range(15,16): # Terminal in each set
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 20 21 0\n0\n25 26 27 0\n0\n1 2 3 0\n0\n18 18 18 0\n0\n10 10\n10\n0\n0")
        f.write('\n')
for i in range(16,17): # All terminals and honors
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 0\n1\n27 27 27 0\n0\n1 1 1 0\n0\n10 10 10 0\n0\n28 28\n28\n0\n0")
        f.write('\n')
for i in range(17,18): # Little three dragons
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("20 21 22 0\n0\n5 6 7 0\n0\n32 32 32 0\n0\n33 33 33 0\n0\n34 34\n34\n0\n0")
        f.write('\n')
for i in range(18,19): # Half-flush
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 0\n0\n20 21 22 0\n0\n23 24 25 0\n0\n29 29 29 0\n0\n32 32\n32\n0\n0")
        f.write('\n')
for i in range(19,20): # Flush
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f: # 7 Pairs
        f.write("19 20 21 0\n0\n20 21 22 0\n0\n21 22 23 0\n0\n24 24 24 0\n0\n27 27\n27\n0\n0")
        f.write('\n')
for i in range(20,21): # Four concealed triplets 
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 0\n0\n20 20 20 0\n0\n3 3 3 0\n0\n4 4 4 0\n0\n14 14\n4\n0\n0")
        f.write('\n')
for i in range(21,22): # Four concealed triplets single wait
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 0\n0\n2 2 2 0\n0\n5 5 5 0\n0\n16 16 16 0\n0\n31 31\n31\n0\n0")
        f.write('\n')
for i in range(22,23): # Big three dragons
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("10 11 12 0\n0\n32 32 32 0\n0\n33 33 33 0\n0\n34 34 34 0\n0\n18 18\n18\n0\n0")
        f.write('\n')
for i in range(23,24): # Little four winds
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("1 2 3 0\n0\n28 28 28 0\n0\n29 29 29 0\n0\n30 30 30 0\n0\n31 31\n31\n0\n0")
        f.write('\n')
for i in range(24,25): # Big four winds
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("28 28 28 0\n0\n29 29 29 0\n0\n30 30 30 0\n0\n31 31 31 0\n0\n5 5\n5\n0\n0")
        f.write('\n')
for i in range(25,26): # All honors
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("28 28 28 0\n1\n29 29 29 0\n0\n30 30 30 0\n0\n32 32 32 0\n0\n33 33\n33\n0\n0")
        f.write('\n')
for i in range(26,27): # All terminals
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 0\n1\n27 27 27 0\n0\n1 1 1 0\n0\n9 9 9 0\n0\n10 10\n10\n0\n0")
        f.write('\n')
for i in range(27,28): # All green
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("11 11 11 0\n1\n12 12 12 0\n0\n13 13 13 0\n0\n15 15 15 0\n0\n33 33\n33\n0\n0")
        f.write('\n')
for i in range(28,29): # Nine gates 
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 0\n0\n19 20 21 0\n0\n22 23 24 0\n0\n25 26 27 0\n0\n27 27\n27\n0\n0")
        f.write('\n')
for i in range(29,30): # Nine gates nine wait #####
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 0\n0\n20 21 22 0\n0\n24 25 26 0\n0\n27 27 27 0\n0\n23 23\n23\n0\n0")
        f.write('\n')
for i in range(30,31): # Four kans
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_"+str(i)+'.in', 'w') as f:
        f.write("19 19 19 19 0\n0\n2 2 2 2 0\n0\n12 12 12 12 0\n0\n28 28 28 28 0\n0\n33 33\n33\n0\n0")
        f.write('\n')

# 1 to 9: 1 Pin to 9 Pin
# 10 to 18: 1 So to 9 So
# 19 to 27: 1 Wan to 9 Wan
# 28 to 31: East South West North
# 32 to 34: White Green Red