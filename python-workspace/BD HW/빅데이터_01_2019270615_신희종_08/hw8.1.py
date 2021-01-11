import numpy as np
from numpy.linalg import inv

x1=np.linspace(0,4,15000)
sigma=1
error=np.random.normal(0,sigma,len(x1))
y=2+3*x1+error

y1=y-2
y2=y-3*x1

x0_0=[2]*len(x1)
x0_1=[1]*len(x1)
x1_0=x1*3

X0=[x0_1,x1_0]
X0=np.array(X0)
X0=X0.T

X1=[x0_0,x1]
X1=np.array(X1)
X1=X1.T

Y=np.array(y)
Y=Y.T

beta1=np.dot(np.dot(inv(np.dot(X1.T,X1)),X1.T),Y)[1]
beta0=np.dot(np.dot(inv(np.dot(X0.T,X0)),X0.T),Y)[0]
print("a= ",beta1)
print("b= ",beta0)





