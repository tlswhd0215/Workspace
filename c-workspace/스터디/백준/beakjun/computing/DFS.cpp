#include <iostream>
#include <chrono>
using namespace std;
#define N 20
bool check[21] = { false };
void test() {
	int x = 1;
	for (int i = 0; i < 10000; i++)
		x++;
}
void DFS(int index, int count) {
	if (count == 10)
	{	
		test();
		return;
	}
	for (int i = index; i <= N - 9 + count; i++) {
		if (check[i])continue;
		check[i] = true;
		DFS(i, count + 1);
		check[i] = false;
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	auto start = chrono::high_resolution_clock::now();
	DFS(1, 0);
	auto end = chrono::high_resolution_clock::now();
	cout << (end - start).count();

}