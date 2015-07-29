#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;

	string f, s, c;

	map <string, set <string> > Map;

	for (int i = 0; i < n; i++) {
	 	cin >> f >> s >> c;
	 	Map[c].insert(f + s);
	}

	for (map <string, set <string> > :: iterator it = Map.begin(); it != Map.end(); it++) {
	 	cout << it -> first << ' ' << (it -> second).size() << endl;
	}

	return 0;
}
