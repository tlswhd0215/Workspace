/*#include <iostream>
#include <string>
using namespace std;
void r_combination(); //조합
void permutation(); //순열
int nCr(int n, int r); //C(n,r) 구하기
int fac(int a);//a! 구하기
void nswap(int arr[], int i1, int i2); //배열과 인덱스를 전달받아 swap 진행
int main() {
	int menu;

	while (1) {
		cout << "메뉴 선택 (1:조합 2:순열 3:종료) ";
		cin >> menu;

		switch (menu) {
		case 1:
			r_combination();
			cout << endl;
			break;
		case 2:
			permutation();
			cout << endl;
			break;
		case 3:
			return 0;
		default:
			cout << "잘못된 메뉴\n";
			exit(1);
		}
	}
}
void permutation() {
	string buf;
	int m, len, k, p, q;
	cout << "문자열 입력 : ";
	cin >> buf;
	len = buf.length();

	int* per = new int[len];
	for (int i = 0; i < len; i++)
		per[i] = i;
	for (int i = 0; i < len; i++)
		cout << buf[per[i]];
	cout << endl;
	for (int i = 1; i < fac(len); i++) {
		m = len - 2;

		while (per[m] > per[m + 1])
			m -= 1;

		k = len - 1;

		while (per[m] > per[k])
			k -= 1;

		nswap(per, m, k);
		p = m + 1;
		q = len - 1;
		while (p < q) {
			nswap(per, p, q);
			p += 1;
			q -= 1;
		}
		for (int i = 0; i < len; i++)
			cout << buf[per[i]];
		cout << endl;
	}
	
}
int fac(int a) {
	int num = 1;
	for (int i = 2; i <= a; i++)
		num *= i;
	return num;
}
int nCr(int n, int r) {
	int k = n - r > r ? r : n - r;
	int num = 1;
	int sub = 1;

	for (int i = 1; i <= k; i++) {
		num *= n + 1 - i;
		sub *= i;
	}
	return num / sub;
}
void nswap(int arr[],int i1,int i2) {
	int temp;
	temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}
void r_combination() {
	string buf;
	int r, m, max_val, len;

	cout << "문자열 입력 : ";
	cin >> buf;
	len = buf.length();

	cout << "r 입력 : ";
	cin >> r;

	int* com = new int[r];
	for (int i = 0; i < r; i++)
		com[i] = i;
	for (int i = 0; i < r; i++)
		cout << buf[com[i]];

	for (int i = 1; i < nCr(len, r); i++) {
		cout << endl;
		m = r - 1;
		max_val = len - 1;
		while (com[m] == max_val) {
			m = m - 1;
			max_val = max_val - 1;
		}
		com[m] += 1;
		for (int j = m + 1; j < r; j++) {
			com[j] = com[j - 1] + 1;
		}
		for (int i = 0; i < r; i++)
			cout << buf[com[i]];
	}
}*/
#include <iostream>
using namespace std;
void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void Generating_Permutation(char s[]) {
	int len = 0;
	for (int i = 0; s[i]; i++) {
		len++;
	}
	for (int i = 0; i < len; i++) {
		s[i] = i;
		cout << s[i];
	}
	cout << endl;
	int nFactorial = 1;
	for (int i = 1; i <= len; i++) {
		nFactorial *= i;
	}
	int m;
	int k;
	int p, q;
	for (int i = 1; i < nFactorial; i++) {
		m = len - 2;
		while (s[m] > s[m + 1]) {
			m = m - 1;
		}
		k = len - 1;
		while (s[m] > s[k])
			k = k - 1;
		swap(s[m], s[k]);
		p = m + 1;
		q = len-1;
		while (p < q) {
			swap(s[p], s[q]);
			p = p + 1;
			q = q - 1;
		}
		for (int i = 0; i < len; i++) {
			cout << s[i];
		}
		cout << endl;
	}
}
void Generating_Combination(char s[], int r) {
	int len = 0;
	for (int i = 0; s[i]; i++) {
		len++;
	}
	for (int i = 0; i < r; i++) {
		cout << s[i];
	}
	cout << endl;
	int combination = 1;
	for (int i = 1; i <= len; i++) {
		combination *= i;
	}
	for (int i = 1; i <= r; i++) {
		combination /= i;
	}
	for (int i = 1; i <= len - r; i++) {
		combination /= i;
	}
	int m;
	int max_val = len;
	for (int i = 1; i < combination; i++) {
		m = r - 1;
		max_val = len - 1;
		while (s[m] == max_val) {
			m = m - 1;
			max_val = max_val - 1;
		}
		s[m] = s[m] + 1;
		for (int j = m + 1; j <= r; j++)
			s[j] = s[j - 1] + 1;
		for (int i = 0; i < r; i++) {
			cout << s[i];
		}
		cout << endl;
	}
}
int main() {
	int menu;
	cout << "메뉴 입력(1: 조합,  2: 순열, 3: 종료) >> ";
	cin >> menu;
	int r;
	char str[100] = { 0 };
	switch (menu) {
	case 1:
		cout << "문자열 입력 >> ";
		cin >> str;
		for (int i = 0; str[i]; i++) {
			cout << str[i];
		}
		cout << endl;
		cout << "선택할 문자의 개수 입력 >> ";
		cin >> r;
		Generating_Combination(str, r);
		break;
	case 2:
		cout << "문자열 입력 >> ";
		cin >> str;
		Generating_Permutation(str);
		break;
	case 3:
		return 0;
	}
}