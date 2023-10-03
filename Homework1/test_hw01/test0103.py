import random as r
p=3
for i in range(0,5):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-10,10))+','+str(r.randint(-10,10)))
        f.write('\n')
        f.write(str(r.randint(-10,10))+','+str(r.randint(-10,10)))
        f.write('\n')
for i in range(5,6):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        rx=r.randint(-10,10)
        ry=r.randint(-10,10)
        f.write(str(rx)+','+str(ry))
        f.write('\n')
        f.write(str(rx)+','+str(ry))
        f.write('\n')
for i in range(6,7):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        rx=r.randint(-10,10)
        ry=r.randint(-10,10)
        f.write(str(rx)+','+str(ry))
        f.write('\n')
        f.write(str(rx)+','+str(r.randint(-10,10)))
        f.write('\n')
for i in range(7,8):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        rx=r.randint(-10,10)
        ry=r.randint(-10,10)
        k=r.randint(-10,10)
        f.write(str(rx)+','+str(ry))
        f.write('\n')
        f.write(str(k*rx)+','+str(k*ry))
        f.write('\n')
for i in range(8,10):
    with open('./0'+str(p)+'/in/hw010'+str(p)+'-'+str(i)+'.in', 'w') as f:
        f.write(str(r.randint(-2147483648,2147483647))+','+str(r.randint(-2147483648,2147483647)))
        f.write('\n')
        f.write(str(r.randint(-2147483648,2147483647))+','+str(r.randint(-2147483648,2147483647)))
        f.write('\n')