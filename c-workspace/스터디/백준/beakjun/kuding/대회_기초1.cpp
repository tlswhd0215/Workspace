#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, k, l, c, d, p, nl, np; 
	scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
	printf("%d\n", min(p / (n * np), min((k * l) / (n * nl), (c * d) / n)));
	return 0;
}