#include<iostream>
#include<cstring>
using namespace std;

class Book {
	char *title;
	int price;
public:
	Book(const Book& book);
	Book(const char* title, int price);
	~Book();
	void set(const char* title, int price);
	void show() {
		cout << title << ' ' << price << "원" << endl;
	};
};
Book::Book(const Book& book) {
	this->price = book.price;
	int size = strlen(book.title);
	this->title = new char[size + 1];
	if (!this->title)
		exit(1);
	strcpy(this->title, book.title);
}
Book::Book(const char* title, int price) {
	int size = strlen(title);
	this->title = new char[size + 1];
	if (!this->title)
		exit(1);
	strcpy(this->title, title);
	this->price = price;
}
Book::~Book() {
	delete[] title;
}
void Book::set( char* title, int price) {
	this->price = price;
	if (strlen(this->title) < strlen(title))
	{
		delete[] this->title;
		int size = strlen(title);
		this->title = new char[size+1];
		if (!this->title)
			exit(1);
		strcpy(this->title, title);
	}
	else {
		strcpy(this->title, title);
	}
}
int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}