#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;
#define N 9
#define MAX 100
int arr[N];

void test() {
	int x = 1;
	for (int i = 0; i < 10000; i++)
		x++;
}
void solution(int *arr) {
	int count=0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			test();
			count++;
		}
	}
	cout << count << endl;
}
int main() {
	clock_t start, end;

	start = clock();
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < N; i++) {
		arr[i] = i;
	}
	sort(arr, arr + N);
	solution(arr);

	end = clock();
	cout << end - start;
	return 0;
}