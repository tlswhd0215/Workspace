from matplotlib import pyplot as plt
import numpy as np

data_set=open('f_study.txt','r')
f_study=[float(i)for i in data_set]
data_set.close()
data_set=open('f_nQ.txt','r')
f_nQ=[float(i)for i in data_set]
data_set.close()
data_set=open('p_study.txt','r')
p_study=[float(i)for i in data_set]
data_set.close()
data_set=open('p_nQ.txt','r')
p_nQ=[float(i)for i in data_set]
data_set.close()

x_study=f_study+p_study
x_nQ=f_nQ+p_nQ
py=[1]*len(p_nQ)
fy=[0]*len(f_nQ)
y_d=fy+py
def sigmoid_f(a, x_nQ, b, x_study, c):
    return a * x_nQ + b * x_study + c
def cost_f(a, b, c, x_nQ, x_study, y_d):
    y= sigmoid_f(a, x_nQ, b, x_study, c)
    return (-np.mean(y_d * np.log(y) + (-1*y_d+1) * np.log(1 - y)))
def partial_differntiation(a, b, c, x_nQ, x_study, delta, y_d):
    y= cost_f(a, b, c, x_nQ, x_study, y_d)
    y_delta= cost_f((a + delta), b, c, x_nQ, x_study, y_d)
    gradient_a=(y_delta-y)/delta
    y_delta = cost_f(a, b + delta, c, x_nQ, x_study, y_d)
    gradient_b = (y_delta - y) / delta
    y_delta = cost_f(a, b, c + delta, x_nQ, x_study, y_d)
    gradient_c = (y_delta - y) / delta
    return gradient_a,gradient_b,gradient_c

a_i=np.random.rand(1)
b_i=np.random.rand(1)
c_i=np.random.rand(1)

c_y= cost_f(a_i, b_i, c_i, x_nQ, x_study, y_d)
i_ter=0
delta=0.001
learning_rate=0.3
eps=0.00000005
while(True):
    grad_a,grad_b,grad_c= partial_differntiation(a_i, b_i, c_i, x_nQ, x_study, delta,y_d )
    a_n=a_i+(-grad_a*learning_rate)
    b_n=b_i+(-grad_b*learning_rate)
    c_n=c_i+(-grad_c*learning_rate)
    n_y= cost_f(a_n, b_n, c_n, x_nQ, x_study, y_d)
    i_ter+=1
    if(abs((c_y-n_y))<=eps):
        print('a=',a_n,'b=',b_n,'c=',c_n)
        break
    a_i=a_n
    b_i=b_n
    c_i=c_n
    c_y=n_y