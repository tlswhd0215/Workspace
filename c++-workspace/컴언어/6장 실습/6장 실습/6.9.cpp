#include <iostream>
#include <string>
using namespace std;

class Board {
	static int size;
	static string text[100];
	Board(){}
public:
	static void add(string t);
	static void del(int i);
	static void clear();
	static void print();
	static void modify(int no, string newtext);
};
int Board::size = 0;
string Board::text[100] = { "" };
void Board::add(string t) {
	if (size == 100)
	{
		cout << "�Խ����� �� á���ϴ�." << endl;
		return;
	}
	text[size] = t;
	size++;
}
void Board::del(int i) {
	if (text[i] != "\0"&&i >= 0 && i < size)
	{
		for (int n = i; n < size; n++)
		{
			text[n] = text[n + 1];
		}
		size--;
	}
	else
	{
		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}
}
void Board::clear() {
	for (int i = 0; i < size; i++)
	{
		text[i] = "\0";
	}
	size = 0;
}
void Board::print() {
	cout << "************** �Խ����Դϴ�.**************" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << ": " << text[i] << endl;
	}
}
void Board::modify(int no, string newtext) {
	if (text[no] != "\0"&&no >= 0 && no < size)
		text[no] = newtext;
	else
	{
		cout << "�������� �ʴ� �����Դϴ�." << endl;
		return;
	}
}
int main() {
	Board::add("C++ ����� Ȯ���� �����ֿ� �մϴ�.");
	Board::add("����� Ȯ�� ������� 3���� ���� �ʵ��� ���ּ���.");
	Board::print();

	Board::add("�߰� PL���� �������� ���� �л��� �̹��� ���� �����ϱ� �ٶ��ϴ�.");
	Board::add("6�� �̷� �������� ¦������ ������ �����ϱ��� ��Ź�� �����ϱ� �ٶ��ϴ�.");
	Board::print();

	Board::modify(3, "6�� �̷� �������� ¦������ ������ ȭ���ϱ��� ��Ź�� �����ϱ� �ٶ��ϴ�.");
	Board::print();

	Board::del(4);
	Board::del(2);
	Board::add("6�� �ǽ��� ������ �������� �ϼ��Ͻø� �˴ϴ�.");
	Board::print();

	Board::clear();
	Board::print();

	return 0;
}