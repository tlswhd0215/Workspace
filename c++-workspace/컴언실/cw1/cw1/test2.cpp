#include <iostream>
using namespace std;

int main() {
	char data[10];
	data[0] = 'A';
	data[1] = 'B';
	data[2] = '\0';
	cout << data << endl;
	strcpy(data, "Hello");
	cout << data << endl;
	strcat(data, "!");
	cout << data << endl;

}