#include <iostream>
#include <time.h>
using namespace std;
#define MAX 32767
class Random {
public:
	static void seed() { srand((unsigned int)time(NULL)); }
	static int nextInt(int min = 0, int max = MAX) { return rand() % max + min; }
	static char nextAlphabet() 
	{ 
		if (rand() % 2 == 0)
			return rand() % 25 + 'a';
		else 
			return rand() % 25 + 'A';
	}
	static double nextDouble() { return ((double)(rand() % MAX) / MAX); }
};
int main() {
	Random::seed();
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�." << endl;
	for (int i = 0; i < 10; i++) cout << Random::nextInt(1, 100) << ' ';
	cout << "\n���ĺ��� �����ϰ� 10���� ����մϴ�." << endl;
	for (int i = 0; i < 10; i++) {  cout << Random::nextAlphabet() << ' '; }
	cout << "\n������ �Ǽ��� 10���� ����մϴ�." << endl;
	for (int i = 0; i < 10; i++)cout << Random::nextDouble() << ' ';
}