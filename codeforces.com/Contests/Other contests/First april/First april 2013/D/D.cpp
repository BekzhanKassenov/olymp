#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s;

	cin >> s;

	int n;

	cin >> n;

	for (int i = 0; i < (int)s.size(); i++)
		s[i] = tolower(s[i]);

	for (int i = 0; i < (int)s.size(); i++) {
		char c = s[i];

		if ((int)c < n + 97)
			s[i] = toupper(s[i]);
	}	

	cout << s << endl;

}