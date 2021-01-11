A_Grade = 80
B_Grade = 60
C_Grade = 40
score = int(input('Enter score : '))
if score>=A_Grade:
    print('Your grade is A')
else:
    if score >= B_Grade:
        print('Your grade is B')
    else:
        if score >= C_Grade:
            print('Your grade is C')
        else:
            print('Your grade is F')

