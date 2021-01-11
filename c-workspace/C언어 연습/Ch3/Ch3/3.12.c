#include <stdio.h>
int main()
{
	char name[10];//문자열 변수로 선언한다
	int age;//정수형 변수로 선언한다

	printf("이름 : ");
	scanf(" %s", &name);//변수에 문자열을 입력받아 할당한다

	printf("나이 : ");
	scanf(" %d", &age);//변수에 정수를 입력받아 할당한다

	printf("%s의 나이는 %d세입니다.", name, age);//%s로 문자열을 출력하고 %d로 정수를 출력한다

	return 0;
}