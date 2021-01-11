#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main() {

	long t; 
	scanf("%ld", &t);
	while (t--) {
		long n; 
		scanf("%ld", &n);
		long total(0);
		vector<long> a(n); 
		for (long p = 0; p < n; p++){
			scanf("%ld", &a[p]);
			total += a[p];
		}
		if (total == 0) {
			puts("NO"); 
			continue; 
		}
		else if (total > 0)
		{
			sort(a.begin(), a.end(), greater<>());
		}
		else {
			sort(a.begin(), a.end(), less<>());
		}
		puts("YES");
		for (long p = 0; p <n;p++) {
			printf("%ld ", a[p]); 
		}
		puts("");
	}

	return 0;
}
