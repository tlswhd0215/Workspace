#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int num, i, cnt = 0, total = 0, temp, div, p;
	cout << "양수 입력: ";
	cin >> num;
	cout << "=== 3이 들어간 숫자 리스트 ===" << endl;
	for (i = 2; i <= num; i++) {
		temp = cnt;
		div = i;
		while (div > 0){
			if (div % 10 == 3)cnt++;
			div /= 10;}
		p = total;
		if (temp != cnt){
			total++;
			cout << setw(4) << i;
		}
		if (total % 10 == 0 && total != 0 && p!=total){
			cout << endl;}}
	cout << endl << "------------------------------------------------------------" << endl << "3을 포함하고 있는 숫자의 개수: " << total << endl << "숫자 3의 개수: " << cnt << endl << "------------------------------------------------------------" << endl;
}