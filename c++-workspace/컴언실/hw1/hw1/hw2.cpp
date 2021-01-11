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
	cout << "좌표 입력>>";
	cin >> x1 >> y1 >> x2 >> y2;
	Rectangle rec(x1, y1, x2, y2);
	if (rec.isSquare()) cout << "정사각형입니다." << endl;
	else cout << "정사각형이 아닙니다." << endl;
}