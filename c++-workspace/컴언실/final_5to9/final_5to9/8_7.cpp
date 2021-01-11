#include <iostream>
using namespace std;

class BaseMemory {
	char *mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	~BaseMemory() { delete[] mem; }
	char getMem() { return *mem; }
	char getIndex(int index) { return mem[index]; }
	void setIndex(int index, char c) { mem[index] = c; }
	void setMem(char x[], int size)
	{
		memcpy(mem, x, size);
	}
};
class ROM:protected BaseMemory {
public:
	ROM(int size, char x[], int s) :BaseMemory(size) { setMem(x, s); }
	char read(int index) { return getIndex(index); }
};
class RAM :protected BaseMemory {
public:
	RAM(int size) :BaseMemory(size) {}
	void write(int index, char c) { setIndex(index, c); }
	char read(int index) { return getIndex(index); }
};
int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM bisoROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);

	for (int i = 0; i < 5; i++)mainMemory.write(i, bisoROM.read(i));
	for (int i = 0; i < 5; i++)cout << mainMemory.read(i);
}