#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, K;
	cin >> N >> K;

	long long* S1 = new long long[N];
	long long* S2 = new long long[N];

	for (int i = 0; i < N; i++) {
		cin >> S1[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> S1[2];
	}
	sort(S1, S1 + N);
	sort(S2, S2 + N);

	int low1 = 0;
	int low2 = 0;
	int high1 = N - 1;
	int high2 = N - 1;
	int col;
	int row;
	int cnt = 0;
	int movex = 0;
	int movey = 0;
	long long mid;
	long long result;
	int st = 0;
	while (cnt<=K&&cnt>K-st) {
		cnt = 0;
		col = (low1 + high1) / 2;
		row = (low2 + high2) / 2;
		mid = S1[col] * S2[row];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (mid / S1[i] > S2[j])
					cnt++;
				else if (mid / S1[i] == S2[j])
				{	
					st++;
					cnt++;
				}
				else break;
			}
		}
		if (cnt > K) {
			if(movex==1&&movey==)
		}
		else if (cnt < K) {

		}
	}
	cout << mid;
	return 0;
}