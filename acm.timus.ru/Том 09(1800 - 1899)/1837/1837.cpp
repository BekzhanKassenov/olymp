#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

map <string, set <string> > Map;
map <string, int> ans;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	string a, b, c;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		Map[a].insert(b);
		Map[a].insert(c);
		Map[b].insert(a);
		Map[b].insert(c);
		Map[c].insert(a);
		Map[c].insert(b);
	}

	queue <string> q;
	q.push("Isenbaev");
	ans["Isenbaev"] = 0;

	while (!q.empty()) {
		string cur = q.front();
		q.pop();

		if (!Map.count(cur))
			break;

		for (set <string> :: iterator it = Map[cur].begin(); it != Map[cur].end(); it++)
			if (!ans.count(*it)) {
				ans[*it] = ans[cur] + 1;
				q.push(*it);
			}
	}

	for (map <string, set <string> > :: iterator it = Map.begin(); it != Map.end(); it++) {
		cout << it -> first << ' ';

		if (ans.count(it -> first)) 
			cout << ans[it -> first];
		else
			cout << "undefined";

		cout << endl;	
	}
}
