#include <stdio.h>
#define MAX_STD 5
struct student {
	char name[20];
	int kor, eng, math;
	double average;
};
void input_student(struct student *s);
void output_student(struct student s);
double compute_class_avg(const struct student p[], int size);
int Find_First(const struct student p[], int size);

int main()
{
	struct student std[MAX_STD];
	int i, first;
	double total_average = 0;

	printf("%d ���� �л� ������ �Է��ϼ���.\n", MAX_STD);
	for (i = 0; i < MAX_STD; i++)
	{
		input_student(&std[i]);
	}
	printf("\n �̸� \t���� ���� ����\t���\n");
	for (i = 0; i < MAX_STD; i++)
	{
		output_student(std[i]);
	}
	total_average = compute_class_avg(std, MAX_STD);
	printf("\n��ü ��� : %6.2f\n", total_average);

	first = Find_First(std, MAX_STD);
	printf("\n�츮 �� 1���� %s�Դϴ�.", std[first].name);

	return 0;
}
void input_student(struct student *s)
{
	printf("�̸�: ");
	gets((*s).name);
	printf("����, ����, ���� ����: ");
	scanf(" %d %d %d", &s->kor, &s->eng, &s->math);
	getchar();
	s->average = (s->kor + s->eng + s->math) / 3.0;
}
void output_student(struct student s)
{
	printf("%s\t%4d %4d %4d %4.2f\n", s.name, s.kor, s.eng, s.math, s.average);
}
double compute_class_avg(const struct student p[], int size)
{
	double temp = 0;
	for (int i = 0; i < size; i++)
	{
		temp += p[i].average;
	}
	return temp / size;
}
int Find_First(const struct student p[], int size)
{
	int max=0;
	for (int i = 0; i < size; i++)
	{
		if ((p+i)->average > (p+max)->average)
			max = i;
	}
	return max;
}