#include <iostream>
using namespace std;
char& find(char a[], char c, bool& success);
int main() {
	char s[] = "Mike";
	bool b;
	char& loc1 = find(s, 'k', b);
	if (b == false)
	{
		cout << "k를 발견할 수 없다" << endl;
		return 0;
	}
	loc1 = 'm';
	cout << s << endl;

	char &loc2 = find(s, 'k', b);
	if(b==false)
	{
		cout << "k를 발견할 수 없다" << endl;
		return 0;
	}
	loc2 = 't';
	cout << s << endl;
	return 0;

}
char& find(char a[], char c, bool& success)
{
	int i = 0;
	while (a[i] != NULL)
	{
		if (a[i] == c)
		{
			success = true;
			return a[i];
		}
		else
		{
			success = false;
		}
		i++;
	}
}
