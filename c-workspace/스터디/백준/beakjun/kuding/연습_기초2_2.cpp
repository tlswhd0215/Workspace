# include <iostream>
# define Swap(x,y) {int t=x; x=y; y=t;}
using namespace std;
int arr[100000][2];
void qSorty(int(*arr)[2], int left, int right)
{
	int mright = right;
	int mleft = left;
	int pivotx = arr[(left + right) / 2][0];
	int pivoty = arr[(left + right) / 2][1];

	while (mleft <= mright)
	{
		while (arr[mleft][1] < pivoty || (arr[mleft][1] == pivoty) && arr[mleft][0] < pivotx)mleft++;
		while (arr[mright][1] > pivoty || (arr[mright][1] == pivoty && arr[mright][0] > pivotx))mright--;

		if (mleft <= mright)
		{
			Swap(arr[mleft][0], arr[mright][0]);
			Swap(arr[mleft][1], arr[mright][1]);
			mleft++; mright--;
		}
	}
	if (left < mright)qSorty(arr, left, mright);
	if (mleft < right)qSorty(arr, mleft, right);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf(" %d %d", &arr[i][0], &arr[i][1]);
	}
	qSorty(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", arr[i][0], arr[i][1]);
	}
}