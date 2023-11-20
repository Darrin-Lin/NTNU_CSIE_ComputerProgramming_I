import random as r
hw=4
hw_part=3
for i in range(0,1):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("#include <stdint.h>\n")
        f.write("#pragma once\n")
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
        
        for k in range(0,11):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+1))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(11,24):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+3))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(24,49):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+5))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(49,74):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+7))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(74,87):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+9))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(87,100):
            f.write("{")
            for j in range(0,6):
                f.write("15")
                if j!=5:
                    f.write(",")
            f.write("},\n")
        f.write("};")
        f.write('\n')

for i in range(1,4):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("#include <stdint.h>\n")
        f.write("#pragma once\n")
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
for i in range(4,5):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("#include <stdint.h>\n")
        f.write("#pragma once\n")
        n=100
        num=[0,1,2,3,4,5]
        r.shuffle(num)
        f.write("#define STUDENT_NUMBER ("+str(n)+")\n")
        f.write("#define CHINESE ("+str(num[0])+")\n")
        f.write("#define ENGLISH ("+str(num[1])+")\n")
        f.write("#define MATH_A ("+str(num[2])+")\n")
        f.write("#define MATH_B ("+str(num[3])+")\n")
        f.write("#define SOCIAL ("+str(num[4])+")\n")
        f.write("#define SCIENCE ("+str(num[5])+")\n")
        f.write("int32_t score[][6]=")
        f.write("{")
        for k in range(0,11):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+1))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(11,24):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+3))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(24,49):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+5))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(49,74):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+7))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(74,87):
            f.write("{")
            for j in range(0,6):
                f.write(str(j+9))
                if j!=5:
                    f.write(",")
            f.write("},\n")
        for k in range(87,100):
            f.write("{")
            for j in range(0,6):
                f.write("15")
                if j!=5:
                    f.write(",")
            f.write("},\n")
        f.write("};")
        f.write('\n')
for i in range(5,7):
    with open('./0'+str(hw_part)+'/in/hw0'+str(hw)+'0'+str(hw_part)+"_0"+str(i)+'.in', 'w') as f:
        f.write("#include <stdint.h>\n")
        f.write("#pragma once\n")
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
        f.write("#pragma once\n")
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
