#include <iostream>
using namespace std;

class Color {
	int red, blue, green;
public:
	Color(int r = 0, int g = 0, int b = 0) { red = r; blue = b; green = g; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
	friend Color operator +(Color a,Color b) 
	{ 
		Color tmp = a; 
		tmp.red += b.red; 
		tmp.blue += b.blue;
		tmp.green += b.green;
		if (tmp.blue > 255)
			tmp.blue = 255;
		if (tmp.red > 255)
			tmp.red = 255;
		if (tmp.green > 255)
			tmp.green = 255;
		return tmp;
	}
	friend bool operator==(Color a,Color b)
	{
		if (b.red == a.red&&b.green == a.green&&b.blue == a.blue)
			return true;
		else
			return false;
	}
};
int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();
	
	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}
