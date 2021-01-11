#include <iostream>
#include <cstdlib>
using namespace std;
class Rectangle {
public:	
	int width, height;
	Rectangle(int x1, int y1, int x2, int y2);
	bool isSquare();
};
Rectangle::Rectangle(int x1, int y1, int x2, int y2) {
	width = abs(x1 - x2);
	height =abs(y1 - y2);
}
bool Rectangle::isSquare() {
	if (width == height) return true;
	else return false;
}
int main() {
	int x1, y1, x2, y2;
	cout << "��ǥ �Է�>>";
	cin >> x1 >> y1 >> x2 >> y2;
	Rectangle rec(x1, y1, x2, y2);
	if (rec.isSquare()) cout << "���簢���Դϴ�." << endl;
	else cout << "���簢���� �ƴմϴ�." << endl;
}