#include <iostream>
using namespace std;

int main() {
	int n, i = 0;
	cout << "���� �Է�>>";
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