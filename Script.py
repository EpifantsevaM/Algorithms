from random import randint
import os
import time
import matplotlib.pyplot as plt

sizes = []
times = []

for i in range(100):
    size = randint(10, 100000)
    m = [randint(-1000, 1000) for _ in range(size)]
    name = 'input' + str(i).zfill(3) + '.txt'
    name1 = 'output' + str(i).zfill(3) + '.txt'
    f = open(name, 'w')
    f.write(str(size)+'\n')
    for j in m:
        f.write(str(j)+'\n')
    f.close()
    start_time = time.time()
    #os.system('Shellsort.exe '+name+" "+name1)
    #os.system('Qsort.exe ' + name + " " + name1)
    os.system('Heapsort.exe ' + name + " " + name1)
    times.append(time.time() - start_time)
    sizes.append(size)

    m.sort()
plt.scatter(sizes, times)
plt.xlabel('data size')
plt.ylabel('seconds')
plt.show()

