import numpy as np
import math
from matplotlib import pyplot as plt
x=np.linspace(0,4,15)
sigma=1
error=np.random.normal(0,sigma,len(x))
y=1+2*x+error
gauss=lambda x,m:1/(2*math.pi)**0.5*math.exp(-(x-m)**2/2)
a=np.linspace(0,3,10)
b=np.linspace(0,4,10)
likelihood_a=[]
max_b=[]
for i in range(len(a)):
    a_h=a[i]
    likelihood_b = []
    for j in range(len(b)):
        b_h=b[j]
        likelihood_f=0
        for k in range(len(x)):
            x_data=x[i]
            m=b_h+a_h*x_data
            likelihood_f+=math.log10(gauss(y[k],m))
        likelihood_b.append(likelihood_f)
    max_b.append(likelihood_b.index(max(likelihood_b)))
    likelihood_a.append(max(likelihood_b))
max_a=a[likelihood_a.index(max(likelihood_a))]
max_b_i=b[max_b[likelihood_a.index(max(likelihood_a))]]
y_h=max_b_i+max_a*x

plt.figure(1)
plt.plot(a,likelihood_a,'b-')
plt.xlabel('a')
plt.ylabel('ML_f_a')
plt.figure(2)
plt.plot(b,likelihood_a,'b-')
plt.xlabel('b')
plt.ylabel('ML_f_b')
plt.figure(3)
plt.plot(x,y,'b.',label='real data')
plt.plot(x,y_h,'r-',label='estimation')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()