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

	printf("한 점의 좌표를 입력하세요: ");
	scanf(" %d %d", &pt.x, &pt.y);

	switch (isInRect(r, pt))
	{
	case 1:
		printf("(%d, %d)는 사각형의 내부에 있습니다.", pt.x, pt.y);
		break;
	case -1:
		printf("(%d, %d)는 사각형의 외부에 있습니다.", pt.x, pt.y);
		break;
	case 0:
		printf("(%d, %d)는 사각형의 둘레 위에 있습니다.", pt.x, pt.y);
		break;
	}
	return 0;
}
void inputRect(RECT *rp)
{
	int temp;
	while (1) {
		printf("좌상단점/우하단점 좌표를 입력하세요: ");
		scanf(" %d %d %d %d", &rp->leftUp.x, &rp->leftUp.y, &rp->rightDown.x, &rp->rightDown.y);
		if (rp->leftUp.x == rp->rightDown.x || rp->leftUp.y == rp->rightDown.y)
			printf("입력오류!! 입력하신 좌표값으로는 사각형이 성립되지 않습니다\n");
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
	printf("좌상단 점: (%2d,%2d), ", r.leftUp.x, r.leftUp.y);
	printf("우상단 점: (%2d,%2d)\n", r.rightDown.x, r.rightDown.y);
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
