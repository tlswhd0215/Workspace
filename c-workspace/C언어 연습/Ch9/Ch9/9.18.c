#include <stdio.h>
#include <string.h>

char str[80];//�ܿ� ���� ����
char* Replace_String(char *str1, int index, char *str2);
int main()
{
	printf("������ ���ڿ� : %s\n", "We have a book");
	printf("������ ���ڿ� : %s\n", Replace_String("We have a book", 11, "paper"));

	return 0;
}
char* Replace_String(char *str1, int index, char *str2)
{
	strcpy(str, str1);//str�� str1�� ����
	int i;
	for (i=0; str2[i]!=NULL; i++)//�ٲٷ��� �ϴ� ���ڿ��� ����
	{
		str[index + i - 1] = str2[i];//����
	}
	return str;//�ٲ� str�� ����
}