#include <iostream>
#include <string>
using namespace std;
class FC {
	string num;											//�ԷµǴ� ���� �����ϴ� ���ڿ�
	int integer;										//�Էµ� ���� ������ ��� ������ ����
	double real;										//�Էµ� ���� ������ �ƴ� ��� ������ ����
	bool typeInt;										//�Էµ� ���� �������� �ƴ����� ��Ÿ���� ����, �����̸� true
	
	int floor(int x) {									//�Է°��� ������ ���� floor �Լ�
		return x;
	}
	int floor(double x) {								//�Է°��� ������ �ƴ� ���� floor �Լ�
		if (x >= 0)
			return (int)x;
		else
			return (int)x-1;
	}
	int ceiling(int x) {								//�Է°��� ������ ���� ceiling �Լ�
		return x;
	}
	int ceiling(double x) {								//�Է°��� ������ �ƴ� ���� ceiling �Լ�
		if (x >= 0)
			return (int)x+1;
		else
			return (int)x;
	}
public:
	void getNum() {										//���� �Է¹޴� �Լ�
		cout << "Input Num>> ";
		cin >> num;
	}								
	void checkNum() {									//�Էµ� ���� �������� Ȯ���ϴ� �Լ�
		if (stoi(num) == stod(num))						//������ ��ȯ���� ���� �Ǽ��� ��ȯ���� ���� ���� �������� Ȯ��
		{
			integer = stoi(num);
			typeInt = true;
		}
		else {
			real = stod(num);
			typeInt = false;
		}
	}
	void print() {										//��� ���
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
