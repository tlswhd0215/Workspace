#include <iostream>
using namespace std;

int main() {
	int n, i = 0;
	cout << "정수 입력>>";
	cin >> n;
	while (i < n)
	{
		int j = 0;
		while (j <= i)
		{
			cout << "*";
			j++;
		}
		cout << endl;
		i++;
	}
}