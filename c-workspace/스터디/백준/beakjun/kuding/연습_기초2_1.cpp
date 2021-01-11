#include <iostream>
#include <string>
using namespace std;
class Name {
	string name = "noname";
	Name* next;
public:
	Name() { next = NULL; }
	Name* add(Name* n) {
		cin >> this->name;
		this->next = n;
		return n;
	}
	Name* printn() { cout << name << "\n"; return next; }
};
class Member {
	int num = 0;
	Name pStart;
	Name* p = &pStart;
public:
	int age;
	void getM() {
		num++;
		p = p->add(new Name());
	}
	void printN() {
		Name* q = &pStart;
		for (int i = 0; i < num; i++)
		{
			cout << age << " ";
			q = q->printn();
		}
	}
};
int main() {
	ios::sync_with_stdio(false);
	int n, tmp;
	cin >> n;
	Member m[201];
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		m[tmp].age = tmp;
		m[tmp].getM();
	}
	for (int i = 1; i < 201; i++)
	{
		m[i].printN();
	}
}