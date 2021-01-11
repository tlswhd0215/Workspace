import numpy
def correlation_f(list_a,list_b):
    s=0
    for i in range(len(list_a)):
        s+=list_a[i]*list_b[i]
    return s/len(list_a)
def mean_f(list_a):
    return numpy.mean(list_a)
def dev_f(list_a):
    return numpy.std(list_a)
def correlation_coefficient(list_a,list_b):
    return (correlation_f(list_a,list_b)-mean_f(list_a)*mean_f(list_b))/(dev_f(list_a)*dev_f(list_b))

a=[1,2,3,4,5]
b=[2,4,3,1,1]

print(correlation_coefficient(a,b))