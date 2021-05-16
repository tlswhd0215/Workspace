import numpy as np
from matplotlib import pyplot as plt
import timeit
import strassen
import iteration
import divide_and_conquer
i=0
t_strassen=[[]for _ in range (8)]
t_iter=[[]for _ in range (8)]
t_DC=[[]for _ in range (8)]

avg_strassen=[0]*8
avg_iter=[0]*8
avg_dc=[0]*8
size_n=[i+1 for i in range(8)]
while(i<80):
    size=i//10+1
    A=np.random.randint(0,100,(2**size,2**size))
    B=np.random.randint(0,100,(2**size,2**size))

    start_time=timeit.default_timer()
    C_strassen=strassen.strassen(A,B)
    end_time=timeit.default_timer()
    t_strassen[i//10].append(end_time-start_time)

    start_time = timeit.default_timer()
    C_iteration = iteration.iteration(A, B)
    end_time = timeit.default_timer()
    t_iter[i // 10].append(end_time - start_time)

    start_time = timeit.default_timer()
    C_DC = divide_and_conquer.div_con(A, B)
    end_time = timeit.default_timer()
    t_DC[i // 10].append(end_time - start_time)
    i+=1

for j in range (8):
    avg_strassen[j] = np.mean(t_strassen[j])
    avg_iter[j]=np.mean(t_iter[j])
    avg_dc[j]=np.mean(t_DC[j])
    print("#",j+1," size ",2**(j+1))
    print("strassen",np.mean(t_strassen[j]))
    print("iter",np.mean(t_iter[j]))
    print("Divide and Conquer",np.mean(t_DC[j]))

plt.plot(size_n,avg_iter,c='g',label='Iterative')
plt.plot(size_n,avg_strassen,c='r',label='Strassen')
plt.plot(size_n,avg_dc,c='b',label='Divide and Conquer')
plt.scatter(size_n,avg_iter,c='g')
plt.scatter(size_n,avg_strassen,c='r')
plt.scatter(size_n,avg_dc,c='b')
plt.xlabel('log n')
plt.ylabel('time (s)')
plt.title('Excution Time')
plt.legend()
plt.show()




