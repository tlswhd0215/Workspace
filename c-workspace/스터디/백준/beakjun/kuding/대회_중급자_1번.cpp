#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {

	const int B = 101;
	const int D = 5;
	vector<int> count(B + 1, 0);

	int n, k; 
	cin >> n >> k;

	for (int p = 0; p < n; p++) {
		string s; 
		cin >> s;
		++count[s.size()];
	}

	string pwd; 
	cin >> pwd;

	int prev(0);
	for (int p = 0; p < pwd.size(); p++) { prev += count[p]; }
	int cur = prev + count[pwd.size()];
	cout << (prev + 1 + (prev / k) * D) << " " << (cur + (cur - 1) / k * D) << endl;

	return 0;
}