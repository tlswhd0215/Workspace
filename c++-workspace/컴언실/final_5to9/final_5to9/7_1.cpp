#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	//Book operator +=(int a) { price += a; return *this; }
	//Book operator -=(int a) { price -= a; return *this; }
	//friend Book operator+=(Book& a, int b) { a.price += b; return a; }
	//friend Book operator-=(Book& a, int b) { a.price -= b; return a; }
	//bool operator ==(int p) { if (price == p)return true; else return false; }
	//bool operator ==(Book a) { if (price == a.price&&pages == a.pages&&title == a.title)return true; else return false; }
	//bool operator ==(string s) { if (title == s)return true; else return false; }
	//friend bool operator ==(Book a,int p) { if (a.price == p)return true; else return false; }
	//friend bool operator ==(Book a,Book b) { if (a.price == b.price&&a.pages == b.pages&&a.title == b.title)return true; else return false; }
	//friend bool operator ==(Book a,string s) { if (a.title == s)return true; else return false; }
	//bool operator!() { if (price == 0)return true; else return false; }
	friend bool operator<(string a, Book b) { if (b.title > a)return true; else return false; }
	string getTitle() { return title; }
};
int main() {
	Book a("��ǰ C++", 30000, 300), b("��ǰ C++", 30000, 500),book("�������",0,50),c("û��",20000,300);
	//a += 500;
	//b -= 500;
	//a.show();
	//b.show();
	//if (a == 30000)cout << "���� 30000��" << endl;
	//if (a == "��ǰ C++")cout << "��ǰ C++ �Դϴ�." << endl;
	//if (a == b)cout << "�� å�� ���� å�Դϴ�." << endl;
	//if (!book)cout << "��¥��" << endl;
	string d;
	cout << "å �̸��� �Է��ϼ���>>";
	getline(cin, d);
	if (d < c)
		cout << c.getTitle() << "�� " << d << "���� �ڿ� �ֱ���!" << endl;
}