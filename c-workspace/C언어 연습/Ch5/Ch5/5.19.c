#include <stdio.h>
int main()
{
	double no1, no2;//���� ����
	char op;//���� ����
	printf("�Է�(�����ȣ, ����, ����) : ");//���ù� ���
	scanf(" %c %lf %lf", &op, &no1, &no2);//���� �Է¹ޱ�
	switch (op)//op�� ���� ���� case���� ������ ����
	{
	case '+'://op�� +�� �ԷµǾ��� ���
		printf("������ : %f", no1 + no2);//���ϱ� ������ ���
		break;//switch ���� ���� 
	case '-'://op�� -�� �ԷµǾ��� ���
		printf("������ : %f", no1 - no2);//���������� ���
		break;//switch ���� ���� 
	case '*'://op�� *�� �ԷµǾ��� ���
		printf("������ : %f", no1 * no2);//���������� ���
		break;//switch ���� ���� 
	case '/'://op�� /�� �ԷµǾ��� ���
		printf("������ : %f", no1 / no2);//������������ ���
		break;//switch ���� ���� 
	default://���� ���� �����ڰ� �ԷµǾ��� ���
		printf("Invaid Input");//���
	}
	return 0;
}