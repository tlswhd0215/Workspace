#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int num, i, cnt = 0, total = 0, temp, div, p;
	cout << "��� �Է�: ";
	cin >> num;
	cout << "=== 3�� �� ���� ����Ʈ ===" << endl;
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
	cout << endl << "------------------------------------------------------------" << endl << "3�� �����ϰ� �ִ� ������ ����: " << total << endl << "���� 3�� ����: " << cnt << endl << "------------------------------------------------------------" << endl;
}