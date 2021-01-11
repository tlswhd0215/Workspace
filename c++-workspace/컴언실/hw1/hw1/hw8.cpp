#include <iostream>
using namespace std;

int main() {
	int arr[5], i, j, index, temp;
	cout << "숫자 5개 입력>>";
	for (i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	for (i = 0; i < 4; i++)
	{
		index = i;
		for (j = i + 1; j < 5; j++)
			if (arr[index] > arr[j])
				index = j;
		if (i != index)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}

	}
	for (i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
}