a=[]
b=1
for i in range(3):
    a.append(int(input('정수 입력?')))
    if (a[i]<50):
        b=0
if(b):
    print('평균:',sum(a)/3.0)
else:
    print('과락 발생')
