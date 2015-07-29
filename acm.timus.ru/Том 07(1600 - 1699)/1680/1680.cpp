#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

void parse(const string& s, string& ans, int& nmb) {
	int pos = 0;

	for (; pos < (int)s.size() && s[pos] != '#'; pos++)
		ans += s[pos];

	pos++;

	if (pos < (int)s.size())
		nmb = s[pos] - '0';
	else
		nmb = 0;	
}

map <string, int> Map;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;
	cin >> n;

	int q;
	cin >> q;

	string s;
	getline(cin, s);

	for (int i = 0; i < n; i++) {
		getline(cin, s);
		string tmp;
		int nmb = 0;

		parse(s, tmp, nmb);

		if (!Map.count(tmp)) {
			Map[tmp] = nmb;
			if ((int)Map.size() > q) {
				cout << s << endl;
				return 0;
			}
		}
	}
	return 0;

}
