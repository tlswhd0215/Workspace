#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define MAX_SIZE 101
void sort(int[], int); /*selection sort*/
int binsearch(int list[], int searchnum, int left, int right);
int compare(int x, int y);
int main() {
	int i, n, searchnum, left = 0, right, res, j;
	int list[MAX_SIZE];
	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);
	right = n - 1;
	if (n<1 || n>MAX_SIZE) {
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter the number to put in the list: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}
	printf("\n array:\n ");
	for (i = 0; i < n; i++) /* print out sorted numbers*/
		printf("%d  ", list[i]);
	for (i = 1; i < 9; i++) {
		printf("\nEnter the number to search: ");
		scanf("%d", &searchnum);
		res = binsearch(list, searchnum, left, right);
		if (res == -1)
			right++;
		printf("\n searchnum : %d", res);
	}
	printf("\n");
	for (int i = 0; i < right; i++)
	{
		printf("index %d = %d\n", i, list[i]);
	}
}
int compare(int x, int y)
{
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}
int binsearch(int list[], int searchnum, int left, int right)
/* search list[0] <= list[1] <= . . . <= list[n-1] )for searchnum. Return its position if found. Otherwise retern -1 */
{
	int middle, j, n;
	n = right;
	if (list[n] == 0) {
		n--;
	}
	right = n;
	middle = (left + right) / 2;
	while (left <= right) {
		switch (compare(list[middle], searchnum)) {
		case -1: left = middle + 1;
			break;
		case 0: return middle;
			break;
		case 1: right = middle - 1;
			break;
		}
		middle = (left + right) / 2;
	}
	if (list[middle] < searchnum)
	{
		for (j = n; j > middle; j--)
		{
			list[j + 1] = list[j];


		}
		list[middle + 1] = searchnum;
	}
	else if (list[middle] > searchnum)
		for (j = n; j >= middle; j--)
		{
			list[j + 1] = list[j];
			list[middle] = searchnum;
		}

	return -1;
}
void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}