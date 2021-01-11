#include <stdio.h>

int main()
{
	char ch;//변수 ch의 데이터형을 문자로 선언한다.
	printf("한 문자 입력 : ");//한 문자를 입력하라는 지시어를 출력한다.
	ch = getchar();//콘솔에서 한 문자를 입력하여 ch에 할당한다.
	printf("입력한 문자의 (%c)의 ASCII값 : %d", ch, ch);//%c로 콘솔에서 입력받은 문자를 출력하고 %d로 그 문자의 ASCII코드를 출력한다.


	return 0;

}