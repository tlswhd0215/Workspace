num = int(input('네 자리 이하로 정수를 입력하시오.'))
sum = 0
for i in range (4):
    sum += num//10**(3-i)
    num %= 10**(3-i)
print('자리수의 합=',sum)