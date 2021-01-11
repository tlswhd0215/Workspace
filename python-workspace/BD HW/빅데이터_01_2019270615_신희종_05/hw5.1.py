import matplotlib.pyplot as plt
import random

total=1000
n=100
rand_v=[]
var_p=[0]*(n*5+1)
for i in range(total):
    s=0
    for j in range(n):
         s+=random.randint(1,5)
    rand_v.append(s)
for i in range(total):
    var_p[rand_v[i]]+=1
for i in range(n*5):
    var_p[i] /= 1000

plt.bar(range(n, n*5 + 2),var_p[n-1:])
plt.show()
