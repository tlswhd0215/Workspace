#include<iostream>
#include<string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(const Book& book);
	Book(string title, int price);
	~Book();
	void set(string title, int price);
	void show() {
		cout << title << ' ' << price << "��" << endl;
	};
};
Book::Book(const Book& book) {
	this->price = book.price;
	this->title = book.title;
}
Book::Book(string title, int price) {
	this->title = title;
	this->price = price;
}
Book::~Book() {
	
}
void Book::set(string title, int price) {
	this->price = price;
	this->title = title;
}
int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}