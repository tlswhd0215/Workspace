#include <stdio.h>
#include <math.h>
typedef struct point {
	int x, y;
}POINT;
typedef struct rectangle {
	POINT leftUp;
	POINT rightDown;
}RECT;
void displayRect(RECT r);
void inputRect(RECT *rp);
int isInRect(RECT rec, POINT p);
int main()
{
	RECT r;
	POINT pt;

	inputRect(&r);
	displayRect(r);

	printf("�� ���� ��ǥ�� �Է��ϼ���: ");
	scanf(" %d %d", &pt.x, &pt.y);

	switch (isInRect(r, pt))
	{
	case 1:
		printf("(%d, %d)�� �簢���� ���ο� �ֽ��ϴ�.", pt.x, pt.y);
		break;
	case -1:
		printf("(%d, %d)�� �簢���� �ܺο� �ֽ��ϴ�.", pt.x, pt.y);
		break;
	case 0:
		printf("(%d, %d)�� �簢���� �ѷ� ���� �ֽ��ϴ�.", pt.x, pt.y);
		break;
	}
	return 0;
}
void inputRect(RECT *rp)
{
	int temp;
	while (1) {
		printf("�»����/���ϴ��� ��ǥ�� �Է��ϼ���: ");
		scanf(" %d %d %d %d", &rp->leftUp.x, &rp->leftUp.y, &rp->rightDown.x, &rp->rightDown.y);
		if (rp->leftUp.x == rp->rightDown.x || rp->leftUp.y == rp->rightDown.y)
			printf("�Է¿���!! �Է��Ͻ� ��ǥ�����δ� �簢���� �������� �ʽ��ϴ�\n");
		else
			break;
	}
	if (rp->leftUp.y < rp->rightDown.y)
	{
		temp = rp->leftUp.y;
		rp->leftUp.y = rp->rightDown.y;
		rp->rightDown.y = temp;
	}
	if (rp->leftUp.x > rp->rightDown.x)
	{
		temp = rp->leftUp.x;
		rp->leftUp.x = rp->rightDown.x;
		rp->rightDown.x = temp;
	}
}
void displayRect(RECT r){
	printf("�»�� ��: (%2d,%2d), ", r.leftUp.x, r.leftUp.y);
	printf("���� ��: (%2d,%2d)\n", r.rightDown.x, r.rightDown.y);
}
int isInRect(RECT rec, POINT p) 
{
	if (p.x == rec.leftUp.x || p.x == rec.rightDown.x || p.y == rec.leftUp.y || p.y == rec.rightDown.y)
		return 0;
	else if (p.x > rec.rightDown.x || p.x < rec.leftUp.x || p.y<rec.rightDown.y || p.y>rec.leftUp.y)
		return -1;
	else 
		return 1;
}
