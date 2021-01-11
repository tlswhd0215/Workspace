#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Gameobject {
protected:
	int distance;
	int x, y;
public:
	Gameobject(int startX, int startY, int distance) {
		x = startX;
		y = startY;
		this->distance = distance;
	}
	virtual ~Gameobject() {};
	virtual void move() = 0;
	virtual char getShape() = 0;

	int getX() { return x; }
	int getY() { return y; }
	bool collide(Gameobject *p) {
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};
class Monster :public Gameobject {
public:
	Monster(int startX, int startY, int distance=2) :Gameobject(startX, startY, distance){}
	char direction[4] = { 'u','d','r','l' };
	void move() {
		srand((unsigned int)time(NULL));
		switch (direction[rand() % 3])
		{
		case 'u':
			y += distance;
			if (y == 10)
				y = 0;
			if (y == 11)
				y = 1;
			break;
		case 'd':
			y -= distance;
			if (y = -2)
				y = 8;
			if (y = -1)
				y = 9;
			break;
		case 'r':
			x += distance;
			if (x == 21)
				x = 1;
			if (x == 22)
				x = 2;
			break;
		case 'l':
			x -= distance;
			if (x == -1)
				x = 19;
			if (x == -2)
				x = 18;
			break;
		}

	}
	char getShape() {
		return 'M';
	}
};
class Human :public Gameobject {
public:
	Human(int startX, int startY, int distance = 1) :Gameobject(startX, startY, distance) {}
	void move() {
		char dir;
		cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >>";
		cin >> dir;
		switch (dir) {
		case 'd':
			y += distance;
			if (y == 10)
				y = 0;
			break;
		case 's':
			y -= distance;
			if (y = -1)
				y = 9;
			break;
		case 'f':
			x += distance;
			if (x == 20)
				x = 0;
			break;
		case 'a':
			x -= distance;
			if (x == -1)
				x = 20;
			break;
		}
	}
	char getShape() {
		return 'F';
	}
};
class Food :public Gameobject {
public:
	Food(int startX, int startY, int distance = 1) :Gameobject(startX, startY, distance){}
	char direction[4] = { 'u','d','r','l' };
	bool ifmove[5] = { true,false,false,true,false };
	void move() {
		srand((unsigned int)time(NULL));
		if (ifmove[rand() % 4])
		{
			switch (direction[rand() % 3])
			{
			case 'u':
				y += distance;
				if (y == 10)
					y = 0;
				break;
			case 'd':
				y -= distance;
				if (y = -1)
					y = 9;
				break;
			case 'r':
				x += distance;
				if (x == 20)
					x = 0;
				break;
			case 'l':
				x -= distance;
				if (x == -1)
					x = 19;
				break;
			}
		}
	}
	char getShape() {
		return '@';
	}
};
class Game {
public:
	void sorf() {

	}
	void Map(Monster m,Human h,Food f) {
		char location[20][10] = { '-' };
		location[f.getX()][f.getY()] = f.getShape();
		location[h.getX()][h.getY()] = h.getShape();
		location[m.getX()][m.getY()] = m.getShape();
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout<<location[i][j];
			}
			cout << endl;
		}
	}
	
};
int main() {
	Monster m();
	Human h();
	Food f();
	int mtoh;

}