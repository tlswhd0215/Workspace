#include <iostream>
#include <string>
using namespace std;

class Color {
	string c;
public:
	Color() { c = "white"; cout << "�⺻������" << endl; }
	Color(string c) { this->c = c; cout << "�Ű�����������" << endl; }
	~Color() { cout << "�Ҹ���" << endl; }
};
class Palette {
	Color *p;
public:
	Palette() { p = new Color[3]; }
	~Palette() { delete[] p; }
};
int main() {
	Palette *p = new Palette();
	delete p;
}
