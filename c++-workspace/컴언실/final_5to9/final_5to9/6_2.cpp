#include <iostream>
#include <string>
using namespace std;

class Person {
	int id;
	string name;
	double weight;
public:
	Person(int id = 1, string n = "Grace", double w = 20.5)
	{
		this->id = id;
		name = n;
		weight = w;
	}
	void show() { cout << id << ' ' << weight << ' ' << name << endl; }
};

int main() {
	Person grace, ashley(2, "Ashley"), helen(3, "Helen",32.5);
	grace.show();
	ashley.show();
	helen.show();
}