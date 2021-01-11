import math

def differ(x,delta):
    y_delta=func_(x+delta)
    y=func_(x)
    gradient=(y-y_delta)/delta
    return gradient
def func_(p):
    return math.factorial(n)/(math.factorial(k)*math.factorial(n-k))*p**k*(1-p)**(n-k)
delta=0.00001
eps=0.000001
learing_rate=0.001
n=150
k=79

p_i=0.4
l_i=func_(p_i)
iter=0

while(True):
    g_d=differ(p_i,delta)
    p_n=p_i+(-g_d*learing_rate)
    l_i=func_(p_n)
    iter+=1
    if(abs(p_n-p_i)<=eps):
        print('p=',p_n)
        break
    p_i=p_n


