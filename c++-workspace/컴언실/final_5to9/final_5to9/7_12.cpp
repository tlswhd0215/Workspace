#include <iostream>
using namespace std;

class SortedArray {
	int size;
	int *p;
	void sort();
public:
	SortedArray();
	SortedArray(SortedArray& src);
	SortedArray(int p[], int size);
	~SortedArray();
	SortedArray operator +(SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2);
	void show();
};
void SortedArray::sort(){
	int index;
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (p[index] > p[j])
			{
				index = j;
			}
		}
		if(index!=i){
			temp = p[index];
			p[index] = p[i];
			p[i] = temp;
		}
	}
}
SortedArray::SortedArray() {
	p = NULL;
	size = 0;
}
SortedArray::SortedArray(SortedArray& src) {
	this->size = src.size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = src.p[i];
	sort();
}
SortedArray::SortedArray(int p[], int size) {
	this->p = new int[size];
	this->size = size;
	for (int i = 0; i < size; i++)
		this->p[i] = p[i];
	sort();
}
SortedArray::~SortedArray() {
	delete[] p;
}
SortedArray SortedArray::operator+(SortedArray& op2) {
	SortedArray temp;
	temp.size = this->size + op2.size;
	temp.p = new int[temp.size];
	for (int i = 0; i < this->size; i++)temp.p[i] = this->p[i];
	for (int i = this->size; i < temp.size; i++)temp.p[i] = op2.p[i-this->size];
	temp.sort();
	return temp;
}
SortedArray& SortedArray::operator = (const SortedArray& op2) {
	delete[] p;
	size = op2.size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = op2.p[i];
	sort();
	return *this;
}
void SortedArray::show() {
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++)
		cout << p[i] << ' ';
	cout << endl;
}
int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();
}