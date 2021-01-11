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
		cout << "게시판이 꽉 찼습니다." << endl;
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
		cout << "존재하지 않는 공지입니다." << endl;
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
	cout << "************** 게시판입니다.**************" << endl;
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
		cout << "존재하지 않는 공지입니다." << endl;
		return;
	}
}
int main() {
	Board::add("C++ 답안지 확인은 다음주에 합니다.");
	Board::add("답안지 확인 대기인은 3명을 넘지 않도록 해주세요.");
	Board::print();

	Board::add("중간 PL증을 제출하지 않은 학생은 이번주 내로 제출하기 바랍니다.");
	Board::add("6장 이론 연습문제 짝수번만 다음주 월요일까지 교탁위 제출하기 바랍니다.");
	Board::print();

	Board::modify(3, "6장 이론 연습문제 짝수번만 다음주 화요일까지 교탁위 제출하기 바랍니다.");
	Board::print();

	Board::del(4);
	Board::del(2);
	Board::add("6장 실습은 수요일 자정까지 완성하시면 됩니다.");
	Board::print();

	Board::clear();
	Board::print();

	return 0;
}