#include <stdio.h>
struct profit {//����ü ����
	char name[10];
	int num;
	long int sale;
	int pos;
};
struct profit list[50];//����ü �迭 ���� �� �ʱ�ȭ
int main() {
	
	int i = 0;
	printf("�ڷḦ �Է��Ͻÿ�<�۾������ ȸ��� q�� �Է�>\n");
	while (getchar()!="\n")
	{
		printf("ȸ��� (4�ڸ�): ");
		gets(list[i].name);
		if (strcmp(list[i].name, "q") == 0)
			break;
		printf("������ (2�ڸ�): ");
		scanf(" %d", &list[i].num);
		printf("����� (9�ڸ�): ");
		scanf(" %d", &list[i].sale);
		i++;
	}
	int j;
	printf("ȸ���\t������\t�����\t��������\n");
	for (j = 0; j<i; j++)
	{
		list[j].pos=list[j].sale / 4;//�������� ����
		printf("%s\t%d\t%d\t%d\n", list[j].name, list[j].num, list[j].sale, list[j].pos);
	}
	return 0;
}