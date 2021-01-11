#include <iostream>
#include <chrono>
using namespace std;
#define N 30
void test() {
	int x = 1;
	for (int i = 0; i < 10000; i++)
		x++;
}
void solution() {
	for (int j7 = 0; j7 < N - 6; j7++) {
		for (int j6 = j7 + 1; j6 < N - 5; j6++) {
			for (int j5 = j6 + 1; j5 < N - 4; j5++) {
				for (int j4 = j5 + 1; j4 < N - 3; j4++) {
					for (int j3 = j4 + 1; j3 < N - 2; j3++) {
						for (int j2 = j3 + 1; j2 < N - 1; j2++) {
							for (int j1 = j2 + 1; j1 < N; j1++) {
								test();
							}
						}
					}
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	auto start = chrono::high_resolution_clock::now();
	solution();
	auto end = chrono::high_resolution_clock::now();
	cout << (end - start).count();
	return 0;
}