#include <iostream>
#include <string>
using namespace std;

/*class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price) {
		int size = strlen(title);
		this->title = new char[size + 1];
		if (!this->title)
			exit(1);
		strcpy(this->title, title);
		this->price = price;
	}
	Book(const Book& b) {
		this->price = b.price;
		int size = strlen(b.title);
		this->title = new char[size + 1];
		if (!this->title)
			exit(1);
		strcpy(this->title, b.title);
	}
	~Book() {
		delete[] title;
	}
	void set(const char* title, int price) {
		this->price = price;
		if (strlen(this->title) < strlen(title))
		{
			delete[] this->title;
			int size = strlen(title);
			this->title = new char[size + 1];
			if (!this->title)
				exit(1);
			strcpy(this->title, title);
		}
		else {
			strcpy(this->title, title);
		}
	}
	void show() { cout << title << ' ' << price << "원" << endl; }
};*/
class Book {
	string title;
	int price;
public:
	Book(string title, int price) {
		this->title = title;
		this->price = price;
	}
	void set(string title, int price) {
		this->price = price;
		this->title = title;
	}
	void show() { cout << title << ' ' << price << "원" << endl; }
};
int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}