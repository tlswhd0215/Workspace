#include <stdio.h>
int main()
{
	char name[10];//���ڿ� ������ �����Ѵ�
	int age;//������ ������ �����Ѵ�

	printf("�̸� : ");
	scanf(" %s", &name);//������ ���ڿ��� �Է¹޾� �Ҵ��Ѵ�

	printf("���� : ");
	scanf(" %d", &age);//������ ������ �Է¹޾� �Ҵ��Ѵ�

	printf("%s�� ���̴� %d���Դϴ�.", name, age);//%s�� ���ڿ��� ����ϰ� %d�� ������ ����Ѵ�

	return 0;
}