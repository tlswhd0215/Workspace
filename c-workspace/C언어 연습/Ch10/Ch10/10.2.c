#include <stdio.h>
typedef struct complex {
	int real, image;
}COMPLEX;
void COMPLEXADD(COMPLEX a, COMPLEX b, COMPLEX *p);
int main()
{
	COMPLEX c;
	COMPLEX a = { 4,5 };
	COMPLEX b = { 2,3 };
	COMPLEXADD(a, b, &c);
	printf("(%d+%di)+(%d+%di)=%d+%di", a.real, a.image, b.real, b.image, c.real, c.image);

	return 0;
}
void COMPLEXADD(COMPLEX a, COMPLEX b, COMPLEX *p)
{
	p->real = a.real + b.real;
	p->image = a.image + b.image;
}