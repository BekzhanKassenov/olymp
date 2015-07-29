#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;

	cin >> s;

	s[0] = toupper(s[0]);

	cout << s << endl;
}
