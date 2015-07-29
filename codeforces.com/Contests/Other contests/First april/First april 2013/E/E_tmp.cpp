#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;

	cin >> s;

	int len = s.size();

	for (int i = 0; i < len; i++)
		if (s[i] == 'H')
			cout << "Hello World!" << endl;
		else
			cout << s << endl;	

	return 0;
}