#include <iostream>
#include <string>
using namespace std;

class Board {
	static string post[100];
	static int id;
public:
	static void add(string p) {
		post[id] = p;
		id++;
	}
	static void print() {
		cout << "************* �Խ����Դϴ�. ****************" << endl;
		for (int i = 0; i < id; i++)
		{
			cout <<i<<": "<< post[i]<<endl;
		}
	}
};
string Board::post[100] = { "" };
int Board::id = 0;
int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}