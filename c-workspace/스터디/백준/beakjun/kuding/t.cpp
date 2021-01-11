#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int c;
	cin >> c;

	int n;
	int k;
	int result;
	int* arr = new int[c];

	for (int i = 0; i < c; ++i) {
		int j;
		result = 0;

		cin >> n >> k;

		for (j = 1; j < sqrt(n); j++) {
			if (n % j == 0) {
				if (n / j <= k) {
					if (result < n / j) {
						result = n / j;
					}
				}
			}
		}

		if (j == sqrt(n)) {
			if (j <= k) {
				if (result < n / j) {
					result = n / j;
				}
			}
		}

		arr[i] = (result == 0) ? n : n / result;
	}

	for (int i = 0; i < c; i++) {
		cout << arr[i] << endl;
	}


	return 0;
}
