#include <iostream>
using namespace std;

class Statisctics {
	int* p;
	int size;
	int capa;
public:
	Statisctics(int c=1) 
	{
		size = 0;
		capa = c;
		p=new int[capa]; 
		memset(p, 0, capa);
	}
	void Resize(int newcapa) 
	{
		capa = newcapa;
		int *temp = new int[capa];
		memcpy(temp, p, sizeof(int)*size);
		delete[] p;
		p = temp;
	}
	void push_back(int data)
	{
		if (size == capa)
			Resize(capa * 2);
		p[size] = data;
		size++;
	}
	void pop_back() 
	{ 
		p[size] = 0;
		size--; 
	}
	bool operator !() 
	{ 
		if (size == 0)
			return true; 
		else 
			return false; 
	}
	Statisctics& operator <<(int x) 
	{
		push_back(x);
		return *this;
	}
	void operator ~() 
	{ 
		for (int i = 0; i < size; i++)cout << p[i] << ' ';
		cout << endl;
	}
	void operator >>(int& avg)
	{
		int sum=0;
		for (int i = 0; i < size; i++)
			sum += p[i];
		avg= sum / size;
	}
};
int main() {
	Statisctics stat;
	if (!stat)cout << "���� ��� �����Ͱ� �����ϴ�." << endl;

	int x[5];
	cout << "5���� ������ �Է��϶�>>";
	for (int i = 0; i < 5; i++)cin >> x[i];

	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100<< 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg= " << avg << endl;
}