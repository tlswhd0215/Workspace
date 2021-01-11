import numpy as np
def differential(a,b,x,delta,y):
    y_delta=RMSE(a+delta,b,x,y)
    y=RMSE(a,b,x,y)
    gradient=(y_delta-y)/(delta)
    return gradient
def func_(a,b,x):
    return b+a*x
def mean(x):
    return sum(x)/len(x)
def RMSE(a,b,x,y):
    return (mean((y-func_(a,b,x))**2))**0.5

x=np.linspace(0,4,15)
sigma=1
error=np.random.normal(0,sigma,len(x))
y=1+2*x+error
a=np.random.random()
b=np.random.random()
learning_rate=0.001
delta=0.000001
eps=0.0000001
i_iter=0
rmse=0
while(True):
    g_d=differential(a,b,x,delta,y)
    a_n=a-g_d*learning_rate
    b_n=mean(y-a_n*x)
    rmse_n=RMSE(a_n,b_n,x,y)
    i_iter+=1
    if(abs(rmse_n-rmse)<=eps):
        print("a* = ",a_n," b* = ",b_n," min of rmse= ",rmse_n)
        break
    a=a_n
    b=b_n
    rmse=rmse_n
    if(i_iter%100)==0:
        print('i_ter:',i_iter,'a=',a_n,'b=',b_n,'rmse=',rmse_n)
