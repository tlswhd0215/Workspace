#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
class BitSet {
	int BitMap;
public:
	BitSet() { BitMap = 0; }
	BitSet(const char s[]);
	friend ostream& operator<<(ostream& out, BitSet s);
	BitSet operator+(char newElement);
	BitSet operator|(BitSet op2);
	BitSet operator&(BitSet op2);
	friend bool operator<=(BitSet op1, BitSet op2);
	friend BitSet operator~(BitSet s);
	friend BitSet operator-(BitSet op1, BitSet op2);
};
ostream& operator<<(ostream& out, BitSet s) {
	if (!s.BitMap) {
		out << "{ }";
		return out;
	}
	int temp = s.BitMap;
	out << "{";
	for (int i = 0; i < 26; i++) {
		if (temp & 1)
			out << (char)('a' + i) << ", ";
		temp >>= 1;
	}
	out << "\b\b}";
	return out;
}
BitSet::BitSet(const char s[]) {
	BitMap = 0;
	int temp = strlen(s);
	bool arr[26] = { false };
	for (int i = 0;i<temp ; i++) {
		arr[s[i] - 97] = true;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i])
			BitMap |= (int)(pow(2, i));
	}
}
BitSet BitSet::operator+(char newElement) {
	int temp = newElement - 97;
	if (!(BitMap&(int)pow(2, (temp))))
		BitMap = BitMap | (int)(pow(2, temp));
	return *this;
}
BitSet BitSet::operator|(BitSet op2) {
	BitSet tmp;
	tmp.BitMap = this->BitMap | op2.BitMap;
	return tmp;
}
BitSet BitSet::operator&(BitSet op2) {
	BitSet tmp;
	tmp.BitMap = this->BitMap&op2.BitMap;
	return tmp;
}
bool operator<=(BitSet op1, BitSet op2) {
	BitSet tmp;
	tmp.BitMap = op1.BitMap&op2.BitMap;
	if (op1.BitMap == tmp.BitMap)
		return true;
	else
		return false;
}
BitSet operator~(BitSet s) {
	BitSet tmp;
	tmp.BitMap = ~s.BitMap;
	return tmp;
}
BitSet operator-(BitSet op1, BitSet op2) {
	BitSet tmp;
	BitSet not_op2;
	not_op2.BitMap = ~op2.BitMap;
	tmp.BitMap = op1.BitMap&not_op2.BitMap;
	return tmp;
}
int main() {
	BitSet s1, s2("mathematics"), s3, s4;

	s3 = s3 + 't' + 'e' + 's' + 't' + 'i' + 'n' + 'g';
	cout << "s1= " << s1 << "\ns2= " << s2 << "\ns3= " << s3 << "\n\n";

	s1 = s2 & s3;
	cout << s2 << " ¡û " << s3 << " = " << s1 << "\n\n";

	s1 = s2 | s3;
	cout << s2 << " ¡ú " << s3 << " = " << s1 << "\n\n";

	s4 = s1 - s3;
	cout << s1 << " - " << s3 << " = " << s4 << "\n\n";

	s4 = ~s1;
	cout << "~" << s1 << " = " << s4 << "\n\n";

	if (s2 <= s1)
		cout << s2 << " ¡ö " << s1 << "\n\n";

	if (!(s2 <= s3))
		cout << s2 << " is not susbset of " << s3 << "\n\n";

	return 0;
}