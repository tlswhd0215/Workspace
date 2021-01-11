#include <stdio.h>
#include <string.h>

char str[80];//잔역 변수 선언
char* Replace_String(char *str1, int index, char *str2);
int main()
{
	printf("수정전 문자열 : %s\n", "We have a book");
	printf("수정후 문자열 : %s\n", Replace_String("We have a book", 11, "paper"));

	return 0;
}
char* Replace_String(char *str1, int index, char *str2)
{
	strcpy(str, str1);//str에 str1을 복사
	int i;
	for (i=0; str2[i]!=NULL; i++)//바꾸려고 하는 문자열의 범위
	{
		str[index + i - 1] = str2[i];//변경
	}
	return str;//바뀐 str을 리턴
}