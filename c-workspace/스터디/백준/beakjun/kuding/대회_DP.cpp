#include <cstdio>
#include <vector>
using namespace std;

int main() {

	const long long  MOD = 1000000007;
	const long long  N = 2001;

	vector<vector<long long>>f(N, vector<long long>(N, 0));
	for (int p = 0; p < N; p++) {
		f[p][0] = 1;
		for (int q = 1; q <= p; q++) { 
			f[p][q] = (f[p - 1][q - 1] + f[p - 1][q]) % MOD; 
		}
	}

	long long n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	printf("%lld\n", f[n - 1][2 * k] * f[m - 1][2 * k] % MOD);

	return 0;
}