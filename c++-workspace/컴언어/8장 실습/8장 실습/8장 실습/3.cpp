#include <iostream>
#include <string>
using namespace std;

class Product {
	int ID, price;
	string des, maker;
protected:
	int typenum;
public:
	Product(int id, int p, string d, string m) {
		ID = id;
		price = p;
		des = d;
		maker = m;
	}
	int returnID() { return ID; }
	void setProduct() {
		cin.ignore();
		cout << "��ǰ����>>";
		getline(cin, des);
		cout << "������>>";
		cin >> maker;
		cout << "����>>";
		cin >> price;
	}
	void getProduct() {
		cout << "--- ��ǰ ID : " << ID << endl;
		cout << "��ǰ���� : " << des << endl;
		cout << "������ : " << maker << endl;
		cout << "����: " << price << endl;
	}
};
class Book :public Product {
	int isbn;
	string writer;
	string title;
public:
	Book(int id,string d,string m,int p,)
	void setBook() {
		setProduct();
		cout << "å����>>";
		cin >> title;
		cout << "����>>";
		cin >> writer;
		cout << "ISBN>>";
		cin >> isbn;
	}
	void getBook() {
		getProduct();
		cout << "å���� : " << endl;
		cout << "���� : " << endl;
		cout << "ISBN : " << isbn << endl;
	}
};
class ConversationBook : public Book {
	string language;
public:
	void setLanguage() {
		cout << "���>>";
		cin >> language;
	}
	void getLanguage() {
		cout << "��� : " << language << endl;
	}
	void setCon() {
		setBook();
		setLanguage();
	}
	void getCon() {
		getBook();
		getLanguage();
	}
};
class CompactDisc :public Product {
	string singer;
	string album;
public:
	void setSinger() {
		cout << "����>>";
		cin >> singer;
	}
	void getSinger() {
		cout << "���� : " << singer << endl;
	}
	void setAlbum() {
		cout << "�ٹ�����>>";
		cin >> album;
	}
	void getAlbum() {
		cout << "�ٹ����� : " << album << endl;
	}
	void setDisc() {
		setProduct();
		setAlbum();
		setSinger();
	}
	void getDisc() {
		getProduct();
		getAlbum();
		getSinger();
	}
};
void Resizing(Book* b,int bsize)
{
	Book* tmp = new Book[bsize];
	for (int i = 0; i < bsize; i++)
	{
		tmp[i] = b[i];
	}
	delete[] b;
	Book* bb = new Book[bsize + 1];
	for (int i = 0; i < bsize; i++)
	{
		bb[i]= tmp[i] ;
	}
	delete[] tmp;
}
void Resizing(ConversationBook* c,int csize) {
	ConversationBook* tmp = new ConversationBook[csize];
	for (int i = 0; i < csize; i++)
	{
		tmp[i] = c[i];
	}
	delete[] c;
	ConversationBook* b = new ConversationBook[csize + 1];
	for (int i = 0; i < csize; i++)
	{
		c[i] = tmp[i];
	}
	delete[] tmp;
}
void Resizing(CompactDisc* cd,int cdsize) {
	CompactDisc* tmp = new CompactDisc[cdsize];
	for (int i = 0; i < cdsize; i++)
	{
		tmp[i] = cd[i];
	}
	delete[] cd;
	CompactDisc* b = new CompactDisc[cdsize + 1];
	for (int i = 0; i < cdsize; i++)
	{
		cd[i] = tmp[i];
	}
	delete[] tmp;
}
int main() {
	int num, id = 0;
	Product* pro[100];
	cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;
	
}