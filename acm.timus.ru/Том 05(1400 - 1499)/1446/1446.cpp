#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	vector <vector <string> > a(4);

	a[0].push_back("Slytherin");
	a[1].push_back("Hufflepuff");
	a[2].push_back("Gryffindor");
	a[3].push_back("Ravenclaw");

	string s, t;

	int n;

	cin >> n;

	getline(cin, s);

	for (int i = 0; i < n; i++) {
		getline(cin, s);
		getline(cin, t);

		for (int j = 0; j < 4; j++) {
			if (a[j][0] == t)
				a[j].push_back(s);
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << a[i][0] << ':' << endl;

		for (int j = 1; j < (int)a[i].size(); j++)
			cout << a[i][j] << endl;

		cout << endl;
	}

	return 0;
}
