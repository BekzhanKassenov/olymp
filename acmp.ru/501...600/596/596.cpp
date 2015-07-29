#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

#define F first
#define S second

typedef pair <pair <int, int>, int> item;
typedef long long ll;

map <string, int> num;
vector <string> name;
map <int, vector <item> > Map;
int len;

int get_num(const string& s) {
	if (!num.count(s)) {
		num[s] = len++;
		name.push_back(s);
	}

	return num[s];
}

istream& operator >> (istream& in, item& it) {
	in >> it.F.F >> it.F.S >> it.S;

	return in;
}

ll sqr(int n) {
	return (n * 1ll * n);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string nme;
	item it;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nme >> it;

		Map[get_num(nme)].push_back(it);
	}

	int x, y;

	cin >> x >> y;

	cout << len << endl;

	for (int i = 0; i < len; i++) {
		cout << name[i] << ' ';

		int cnt = 0;

		for (size_t j = 0; j < Map[i].size(); j++) {
			item cur = Map[i][j];

			if (sqr(cur.F.F - x) + sqr(cur.F.S - y) <= sqr(cur.S))
				cnt++;
		}

		cout << cnt << endl;
	}

	return 0;
}
