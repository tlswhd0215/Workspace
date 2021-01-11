#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	__int64 sum = 0;
	scanf(" %d %d", &n, &k);
	int *arr = new int[n];
	int *arr2 = new int[k];
	for (int i = 0; i < n; i++) {
		scanf(" %d", &arr[i]);
	}
	for (int i = 0; i < n-k+1; i++) {
		copy(arr + i, arr + k + i, arr2);
		sort(arr2, arr2 + k);
		sum += arr2[(k -1) / 2];
	}
	printf("%l64d", sum);
	delete[] arr;
	delete[] arr2;
}