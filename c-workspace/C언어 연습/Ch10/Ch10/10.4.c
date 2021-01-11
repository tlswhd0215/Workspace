#include <stdio.h>
struct profit {//구조체 정의
	char name[10];
	int num;
	long int sale;
	int pos;
};
struct profit list[50];//구조체 배열 선언 및 초기화
int main() {
	
	int i = 0;
	printf("자료를 입력하시오<작업종료는 회사명에 q를 입력>\n");
	while (getchar()!="\n")
	{
		printf("회사명 (4자리): ");
		gets(list[i].name);
		if (strcmp(list[i].name, "q") == 0)
			break;
		printf("종업원 (2자리): ");
		scanf(" %d", &list[i].num);
		printf("매출액 (9자리): ");
		scanf(" %d", &list[i].sale);
		i++;
	}
	int j;
	printf("회사명\t종업원\t매출액\t매출이익\n");
	for (j = 0; j<i; j++)
	{
		list[j].pos=list[j].sale / 4;//매출이익 설정
		printf("%s\t%d\t%d\t%d\n", list[j].name, list[j].num, list[j].sale, list[j].pos);
	}
	return 0;
}