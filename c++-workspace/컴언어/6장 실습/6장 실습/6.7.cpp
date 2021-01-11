#include <iostream>
#include <time.h>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = 32767);
	static char nextAlphabet();
	static double nextDouble();
};
int Random::nextInt(int min, int max) {
	return rand() % max + min;
}
char Random::nextAlphabet() {
	char alpha[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	return alpha[rand() % 52];
}
double Random::nextDouble() {
	return rand() / (double)RAND_MAX;
}
int main(){
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) { 
		cout<<Random::nextInt(0, 100)<<' '; 
	}
	cout << endl;
	cout << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextAlphabet() <<' ';
	}
	cout << endl;
	cout << "랜덤한 실수를 10개 출력합니다" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << ' ';
	}
}