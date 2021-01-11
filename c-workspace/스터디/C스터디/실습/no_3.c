#include<stdio.h>
int main()
{
    double T, KRW,USD;
    printf("KRW?:");
    scanf(" %lf", &KRW);
    printf("원/달러환율?:");
    scanf(" lf", &T);
    USD = KRW / T;
    printf("KRW %g = USD %g", KRW, USD);
    return 0;
}