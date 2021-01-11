#include <iostream>
#include <chrono>
using namespace std;
#define N 30
int countBits(int value) {
	int count = 0;
	while (value != 0) {
		value = value & (value - 1);
		count++;
	}
	return count;
}
void test() {
	int x = 1;
	for (int i = 0; i < 10000; i++)
		x++;
}
int main() {
	ios_base::sync_with_stdio(false);
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < (1 << N); i++) {
		if(countBits(i)==7)
			test();
	}
	auto end = chrono::high_resolution_clock::now();
	cout << (end - start).count();
	return 0;
}