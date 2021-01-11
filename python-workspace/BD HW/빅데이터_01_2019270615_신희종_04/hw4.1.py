import matplotlib.pyplot as plt
import random
cond=[]
inter=[]
prob=[]
n=0
k=1
total_try=100000
for j in range (1,total_try+1):
    i=random.randint(1,6)
    if(i==3):
        i = random.randint(1,6)
        k+=1
        if(i==3):
            n+=1
    cond.append(n/k)
    inter.append(n/j)
    prob.append(k/j)
print(cond[total_try-1])
print(inter[total_try-1])
plt.plot(range(1,total_try+1),cond,'b',range(1,total_try+1),inter,'r')
plt.legend(['Conditional Probability','Intersection'])
plt.show()