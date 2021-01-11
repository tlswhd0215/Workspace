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
	BitSet operator+(char newElement); //원소 추가
	BitSet operator|(BitSet op2); //합집합
	BitSet operator&(BitSet op2); //교집합
	friend bool operator <=(BitSet op1, BitSet op2); //op1이 op2의 부분집합인지 평가
	friend BitSet operator~(BitSet s); // 여집합(전체 집합 = 소문자 전체)
	friend BitSet operator-(BitSet op1, BitSet op2); //차집합
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
	bool temp[26] = { false };
	int len = strlen(s);
	for (int i = 0; i<len; i++)
	{
			temp[s[i] - 97] = true;
	}
	BitMap = 0;
	for (int i = 0; i < 26; i++)
	{
		if (temp[i])
			BitMap |= int(pow(2, i));
	}
}
BitSet BitSet::operator+(char newElement) {
	int temp = newElement - 97;
	if (!(this->BitMap&(int)(pow(2, temp))))
		this->BitMap |= (int)(pow(2, temp));
	return *this;
}
BitSet BitSet::operator|(BitSet op2) {
	BitSet temp;
	temp.BitMap = this->BitMap | op2.BitMap;
	return temp;
}
BitSet BitSet::operator&(BitSet op2) {
	BitSet temp;
	temp.BitMap = this->BitMap & op2.BitMap;
	return temp;
}
bool operator <=(BitSet op1, BitSet op2) {
	BitSet temp;
	temp.BitMap = op1.BitMap & op2.BitMap;
	if (temp.BitMap == op1.BitMap)
		return true;
	else
		return false;
}
BitSet operator~(BitSet s) {
	BitSet temp;
	temp.BitMap = ~s.BitMap;
	return temp;
}
BitSet operator-(BitSet op1, BitSet op2) {
	BitSet temp;
	temp.BitMap = op1.BitMap ^ (op1.BitMap&op2.BitMap);
	return temp;
}
int main()
{
	BitSet s1, s2("mathematics"), s3, s4;

	s3 = s3 + 't' + 'e' + 's' + 't' + 'i' + 'n' + 'g';	//원소 삽입
	cout << "s1 = " << s1 << "\ns2 = " << s2 << "\ns3 = " << s3 << "\n\n";

	s1 = s2 & s3;		//교집합
	cout << s2 << " ∩ " << s3 << " = " << s1 << "\n\n";

	s1 = s2 | s3;		//합집합
	cout << s2 << " ∪ " << s3 << " = " << s1 << "\n\n";

	s4 = s1 - s3;		//차집합
	cout << s1 << " - " << s3 << " = " << s4 << "\n\n";

	s4 = ~s1;			//여집합
	cout << "~" << s1 << " = " << s4 << "\n\n";

	if (s2 <= s1)
		cout << s2 << " ⊆ " << s1 << "\n\n";

	if (!(s2 <= s3))
		cout << s2 << " is not susbset of " << s3 << "\n\n";

	return 0;
}