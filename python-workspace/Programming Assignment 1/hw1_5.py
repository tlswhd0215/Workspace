num=int(input('수량을 입력 : '))
if num>=10 and num<=19:
    print('amount of display : ',num*99*0.1)
    print('total : ',num*99*0.9)
else:
    if num>=20 and num<=49:
        print('amount of display : ',num*99*0.2)
        print('total : ',num*99*0.8)
    else:
        if num>=50 and num<=99:
            print('amount of display : ',num*99*0.3)
            print('total : ',num*99*0.7)
        else:
            if num>100:
                print('amount of display : ',num*99*0.4)
                print('total : ',num*99*0.6)
            else:
                if num>=0 and num<=9:
                    print('amount of display : ',num*99*0)
                    print('total : ',num*99*1)
                else:
                    print('Error')
            
