import numpy as np
import strassen
import iteration
import divide_and_conquer
i=0
while(i<20):
    size=np.random.randint(0,6)
    A=np.random.randint(0,100,(2**size,2**size))
    B=np.random.randint(0,100,(2**size,2**size))

    C_np=np.dot(A,B)
    C_strassen=strassen.strassen(A,B)
    C_iteration=iteration.iteration(A,B)
    C_DC=divide_and_conquer.div_con(A,B)
    i+=1

    if(np.array_equal(C_np,C_DC)==True and
    np.array_equal(C_np,C_strassen)==True and
    np.array_equal(C_np,C_iteration)==True):
        print("#%d Equal"%i)
    else:
        print("#%d Not Equal"%i)
        break

print("End")
