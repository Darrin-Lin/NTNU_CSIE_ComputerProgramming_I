import random as r
hw=4
hw_part=3
for i in range(0,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("#include <stdint.h>\n")
        n=100
        f.write("#define STUDENT_NUMBER ("+str(n)+")\n")
        f.write("#define CHINESE (0)\n")
        f.write("#define ENGLISH (1)\n")
        f.write("#define MATH_A (2)\n")
        f.write("#define MATH_B (3)\n")
        f.write("#define SOCIAL (4)\n")
        f.write("#define SCIENCE (5)\n")
        f.write("int32_t score[][6]=")
        f.write("{")
        
        for k in range(0,n):
            f.write("{")
            for j in range(0,6):
                f.write(str(r.randint(0,15)))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        f.write("};")
        f.write('\n')
for i in range(5,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("#include <stdint.h>\n")
        n=r.randint(1,100)
        f.write("#define STUDENT_NUMBER ("+str(n)+")\n")
        f.write("#define CHINESE (0)\n")
        f.write("#define ENGLISH (1)\n")
        f.write("#define MATH_A (2)\n")
        f.write("#define MATH_B (3)\n")
        f.write("#define SOCIAL (4)\n")
        f.write("#define SCIENCE (5)\n")
        f.write("int32_t score[][6]=")
        f.write("{")
        
        for k in range(0,n):
            f.write("{")
            for j in range(0,6):
                f.write(str(r.randint(0,15)))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        f.write("};")
        f.write('\n')
for i in range(7,10):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("#include <stdint.h>\n")
        n=r.randint(100,100000)
        f.write("#define STUDENT_NUMBER ("+str(n)+")\n")
        f.write("#define CHINESE (0)\n")
        f.write("#define ENGLISH (1)\n")
        f.write("#define MATH_A (2)\n")
        f.write("#define MATH_B (3)\n")
        f.write("#define SOCIAL (4)\n")
        f.write("#define SCIENCE (5)\n")
        f.write("int32_t score[][6]=")
        f.write("{")
        
        for k in range(0,n):
            f.write("{")
            for j in range(0,6):
                f.write(str(r.randint(0,15)))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        f.write("};")
        f.write('\n')
