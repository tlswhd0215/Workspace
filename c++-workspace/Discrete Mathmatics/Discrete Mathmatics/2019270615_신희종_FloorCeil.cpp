#include <iostream>
#include <string>
using namespace std;
class FC {
	string num;											//입력되는 수를 저장하는 문자열
	int integer;										//입력된 값이 정수일 경우 저장할 변수
	double real;										//입력된 값이 정수가 아닐 경우 저장할 변수
	bool typeInt;										//입력된 값이 정수인지 아닌지를 나타내는 변수, 정수이면 true
	
	int floor(int x) {									//입력값이 정수일 때의 floor 함수
		return x;
	}
	int floor(double x) {								//입력값이 정수가 아닐 때의 floor 함수
		if (x >= 0)
			return (int)x;
		else
			return (int)x-1;
	}
	int ceiling(int x) {								//입력값이 정수일 때의 ceiling 함수
		return x;
	}
	int ceiling(double x) {								//입력값이 정수가 아닐 때의 ceiling 함수
		if (x >= 0)
			return (int)x+1;
		else
			return (int)x;
	}
public:
	void getNum() {										//값을 입력받는 함수
		cout << "Input Num>> ";
		cin >> num;
	}								
	void checkNum() {									//입력된 값이 정수인지 확인하는 함수
		if (stoi(num) == stod(num))						//정수로 변환했을 때와 실수로 변환했을 때의 값이 같은지를 확인
		{
			integer = stoi(num);
			typeInt = true;
		}
		else {
			real = stod(num);
			typeInt = false;
		}
	}
	void print() {										//결과 출력
		if (typeInt)
		{
			cout << "floor function : " << floor(integer) << endl;
			cout << "ceiling function : " << ceiling(integer) << endl;
		}
		else
		{
			cout << "floor function : " << floor(real) << endl;
			cout << "ceiling function : " << ceiling(real) << endl;
		}
		
	}
};
int main() {
	FC test;
	test.getNum();
	test.checkNum();
	test.print();
	return 0;
}
