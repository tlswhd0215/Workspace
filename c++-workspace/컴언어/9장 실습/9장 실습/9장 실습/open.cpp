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
	int part;
public:
	Monster(int startX, int startY, int distance=2) :Gameobject(startX, startY, distance){}
	char direction[4][2] = { {'u','r' } ,{'u','l'} ,{'d','l'} ,{'d', 'r'} };
	void partition(Gameobject* a)
	{
		int xgap = a->getX() - this->getX();
		int ygap = a->getY() - getY();
		if (xgap >= 0 && ygap >= 0)
			part= 0;
		if (xgap < 0 && ygap >= 0)
			part = 1;
		if (xgap < 0 && ygap < 0)
			part = 2;
		if(xgap>=0&&ygap<0)
			part = 3;
	}
	void move() {
		
		switch (direction[part][rand()%2])
		{
		case 'u':
			y -= distance;
			if (y == -2)
				y = 8;
			if (y == -1)
				y = 9;
			break;
		case 'd':
			y += distance;
			if (y == 10)
				y = 0;
			if (y == 11)
				y = 1;
			break;
		case 'r':
			x += distance;
			if (x == 20)
				x = 1;
			if (x == 21)
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
			y -= distance;
			if (y == -1)
				y = 9;
			break;
		case 's':
			y += distance;
			if (y == 10)
				y = 0;
			break;
		case 'f':
			x += distance;
			if (x == 20)
				x = 0;
			break;
		case 'a':
			x -= distance;
			if (x == -1)
				x = 19;
			break;
		}
	}
	char getShape() {
		return 'H';
	}
};
class Food :public Gameobject {
public:
	Food(int startX, int startY, int distance = 1) :Gameobject(startX, startY, distance){}
	char direction[4] = { 'u','d','r','l' };
	bool ifmove[5] = { true,false,false,true,false };
	void move() {
		if (ifmove[rand() % 4])
		{
			switch (direction[rand() % 3])
			{
			case 'd':
				y += distance;
				if (y == 10)
					y = 0;
				break;
			case 'u':
				y -= distance;
				if (y == -1)
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
	Human *h = new Human(rand() % 20, rand() % 10);
	Food *f = new Food(rand() % 20, rand() % 10);
	Monster *m = new Monster(rand() % 20, rand() % 10);

public:
	bool sorf() {
		if (m->collide(h) || m->collide(f))
		{
			cout << "Monster is Winner!!" << endl;
			return false;
		}
		else if (h->collide(f))
		{
			cout << "Human is Winner!!" << endl;
			return false;
		}
		else return true;
	}
	void moves()
	{
		m->partition(h);
		m->move();
		f->move();
		h->move();
	}
	void Map() {
		char location[10][20];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				location[i][j]='-';
			}
		}
		location[f->getY()][f->getX()] = f->getShape();
		location[h->getY()][h->getX()] = h->getShape();
		location[m->getY()][m->getX()] = m->getShape();
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				cout<<location[i][j];
			}
			cout << endl;
		}
	}
	
};
int main() {
	srand((unsigned int)time(NULL));
	Game a;
	while (a.sorf())
	{
		a.Map();
		a.moves();
	}
}