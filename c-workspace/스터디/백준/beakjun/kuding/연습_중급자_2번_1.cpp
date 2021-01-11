#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

	int N, i;
	scanf("%d", &N);

	long long* arr=new long long [N];

	for (i = 0; i < N; i++) scanf("%lld", &arr[i]);
	sort(arr, arr + N);

	printf("%lld\n", arr[0] * arr[N - 1]);
	delete[] arr;
	return 0;
}