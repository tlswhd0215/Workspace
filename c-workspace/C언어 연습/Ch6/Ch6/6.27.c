#include <stdio.h>
int main()
{
	int num, i;//���� ����

	printf("���� ���� �Է� : ");//�Է¹� ���
	scanf(" %d", &num);//num�Է�

	for (i = 2; i <= num; i++)//2���� num���� i�� 1�� ���ϸ鼭 �ݺ��� ����
	{
		if (num%i == 0)//num�� i�� ���������� �������� 0�̸�, �� i�� num�� �����
			break;//�ݺ��� ����
	}
	if (num == i)//���࿡ num�� �Ҽ��̸� for���� i=num�϶� ����ǹǷ� num=i�϶�
		printf("�Է��� %d�� �Ҽ��Դϴ�.", num);//�Ҽ�
	else//i�� num�� �Ǳ����� ����Ǹ�
		printf("�Է��� %d�� �Ҽ��� �ƴմϴ�.", num);//�Ҽ��� �ƴ�

	return 0;
}