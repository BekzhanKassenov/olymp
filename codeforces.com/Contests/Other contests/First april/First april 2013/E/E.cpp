#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;

	cin >> s;

	int len = s.size();

	if (len >= 12 && s[1] == s[4] && s[4] == s[7])
		cout << "Yes";
	else
		cout << "No";	

	return 0;
}