#include <iostream>
#include <cstring>
using namespace std;

class Set {
	char p[26]; // 실제 원소들이 저장될 배열
	int size; // 원소의 갯수
public:
	Set() { size = 0; }
	Set(const char *s);
	friend ostream& operator << (ostream &out, Set s); //Set 객체 출력을 연산자
	Set operator+(char newElement);//원소 추가
	Set operator| (Set op2); //합집합
	Set operator&(Set op2); //교집합
	friend bool operator <=(Set op1, Set op2); //op1이 op2의 부분집합인지 평가
	friend Set operator~(Set s); // 여집합(전체 집합 = 소문자 전체)
	friend Set operator-(Set op1, Set op2); //차집합
};
ostream& operator << (ostream &out, Set s) {
	if (!s.size) {
		cout << "{ }";
		return out;
	}
	out << "{";
	for (int i = 0; i < s.size; i++)
		out << s.p[i] << ", ";
	out << "\b\b}";
	return out;
}
// 생성자함수와 나머지 연산자 함수 정의
Set::Set(const char*s) {
	int len = strlen(s);
	
	this->p[0] = s[0];
	this->size = 1;
	for (int i = 1; i < len; i++) {
		this->operator+(s[i]);
	}
}
Set Set::operator+(char newElement) {
	char* tmp;
	int len = size;
		tmp = strchr(this->p, newElement);
		if (tmp == NULL)
		{
			this->p[this->size] = newElement;
			size++;
		}
	return *this;
}
Set Set::operator| (Set op2) {
	Set temp;
	strcpy(temp.p, this->p);
	for (int i = 0; i < op2.size; i++)
	{
		if(op2.p[i]!=this->p[i])
			temp.operator+(op2.p[i]);
	}
	return temp;
}
Set Set::operator&(Set op2) {
	Set temp;

	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < op2.size; j++)
		{
			if (this->p[i] == op2.p[j])
			{
				temp.operator+(this->p[i]);
				break;
			}
		}
	}
	return temp;
}
bool operator <=(Set op1, Set op2) {
	bool* sub = new bool[op1.size]{ false };
	for (int i = 0; i < op1.size; i++)
	{
		for (int j = 0; j < op2.size; j++)
		{
			if (op1.p[i] == op2.p[j])
				sub[i] = true;
		}
	}
	for (int i = 0; i < op1.size; i++)
	{
		if (!sub[i])
		{	
			delete[] sub;
			return false;
		}
	}
	delete[] sub;
	return true;
}
Set operator~(Set s) {
	Set temp;
	char alpha[26];
	char* tmp;
	for (int i = 0; i < 26; i++)
	{
		alpha[i] = 'a' + i;
	}
	for (int i = 0; i < 26; i++)
	{
		tmp = strchr(s.p, alpha[i]);
		if (tmp == NULL)
			temp.operator+(alpha[i]);
	}
	return temp;
}
Set operator-(Set op1, Set op2) {
	Set temp;
	char* tmp;

	for (int i = 0; i < op1.size; i++)
	{
		tmp = strchr(op2.p, op1.p[i]);
		if(tmp==NULL)
			temp.operator+(op1.p[i]);
	}
	return temp;
}
int main() {
	Set s1, s2("mathematics"), s3, s4;
	s3 = s3 + 't' + 'e' + 's' + 't' + 'i' + 'n' + 'g'; //원소 삽입
	cout << "s1 = " << s1 << "\ns2 = " << s2 << "\ns3 = " << s3 << "\n\n";
	s1 = s2 & s3;//교집합
	cout << s2 << " ∩ " << s3 << " = " << s1 << "\n\n";
	s1 = s2 | s3;//합집합
	cout << s2 << " ∪ " << s3 << " = " << s1 << "\n\n";
	s4 = s1 - s3;//차집합
	cout << s1 << " - " << s3 << " = " << s4 << "\n\n";
	s4 = ~s1; //여집합
	cout << "~" << s1 << " = " << s4 << "\n\n";
	if (s2 <= s1)//부분집합인지 검사
		cout << s2 << " ⊆ " << s1 << "\n\n";
	if (!(s2 <= s3))
		cout << s2 << " is not susbset of " << s3 << "\n\n";
	return 0;
}