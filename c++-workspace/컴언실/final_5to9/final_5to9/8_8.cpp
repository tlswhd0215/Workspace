#include <string>
#include <iostream>
using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
public:
	Printer(string mo, string ma, int pr, int av) { model = mo; manufacturer = ma; printedCount = pr; availableCount = av; }
	void print(int pages){
		
	}
};
class InkjetPrinter :public Printer {
	int availableInk;
public:
	void printInkJet(int pages) {

	}
};
class LaserPrinter :public Printer {
	int availableToner;
public:
	void printLaser(int pages){}
};
