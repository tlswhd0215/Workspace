#include <stdio.h>
int main()
{
	char ch;//���� ����
	printf("������ �Է� : ");//�Է¶� ���
	scanf(" %c", &ch);//������ �Է�
	switch (ch)//ch�� �Էµ� ���� ���� �˸��� case�� ����
	{
	case 'b'://b�� ���
	case 'B'://B�� ���
		printf("BASIC");//BASIC�� ���
		break;//switch�� ����
	case 'c'://c�ϰ��
	case 'C'://C�ϰ��
		printf("COBOL");//COBOL�� ���
		break;//switch�� ����
	case 'f'://f�ϰ��
	case 'F'://F�ϰ��
		printf("FORTRAN");//FORTRAN�� ���
		break;//switch�� ����
	case '��'://l�� ���
	case 'L'://L�ϰ��
		printf("LISP");//LISP�� ���
	case 'p'://p�� ���
	case 'P'://P�� ���
		printf("Pascal");//PASCAL�����
		break;//switch�� ����
	default://���� case�� �ش����� �������
		printf("Invalid Input");
	}
	return 0;
}