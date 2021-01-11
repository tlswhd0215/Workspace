#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	scanf(" %d", &n);
	int *brr = new int[n];
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf(" %d", &brr[i]);
	}

	for (int i = 0; i < n; i++) {
		arr[i] = brr[i]*(i+1) - sum;
		sum += arr[i];
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}