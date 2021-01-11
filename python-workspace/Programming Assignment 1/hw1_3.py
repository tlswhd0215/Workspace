x= int(input("숫자를 입력하시오 : "))
if x==sum(y for y in range(1, x) if x%y==0):
    print("완전수 입니다.")
else:
    print("완전수가 아닙니다.")
