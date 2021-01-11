#include <stdio.h>

int main()
{
	char ch;//변수 ch의 데이터형을 문자로 선언하고 임의의 문자 A를 할당하였다
	printf(" 문자를 입력 : ");
	scanf(" %c", &ch);
	//(콘솔화면에서) 문자 상수
	//입력받아 ch에 할당
	printf(" %c 의 ASCII 값은 %d입니다.", ch, ch);//문자형 자료형을 printf문에서 %d 변환 문자열을 사용해 해당 문자의 ASCII코드 값을 출력한다
	return 0;
}