def max(x,y):
    if(x>=y):
        return x
    else:
        return y
num1,num2,num3=map(int,input("숫자 3개를 입력하세요 ").split())

print("가장 큰 수는 ",max(max(num1,num2),num3))
