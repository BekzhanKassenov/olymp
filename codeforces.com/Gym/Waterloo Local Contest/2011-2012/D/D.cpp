#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	set <string> dir_str, rev_str;
	stringstream res_str;

	while (getline(cin, s)) {
		dir_str.insert(s);
		reverse(all(s));
		rev_str.insert(s);
	}

	for (set <string> :: iterator it = dir_str.begin(); it != dir_str.end(); it++) {
		string cur = *it;
		string rev;

		int len = cur.size();

		bool flag = false;

		for (size_t i = 0; i < len - 1 && !flag; i++) {
			rev += cur.back();
			cur.pop_back();

			flag |= (dir_str.count(cur) && rev_str.count(rev));
		}

		if (flag) {
			res_str << *it << endl;
		}
	}

	printf("%s", res_str.str().c_str());

	return 0;
}