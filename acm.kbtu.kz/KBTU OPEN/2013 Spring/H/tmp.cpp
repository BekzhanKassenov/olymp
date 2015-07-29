#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <set>
#include <map>

using namespace std;

struct Point {
	int x, y;

	Point() : x(0), y(0) {}

	Point(int x, int y) : x(x), y(y) {}

	Point operator - (const Point& p) const {
		return Point(x - p.x, y - p.y);
	}

	int operator * (const Point& p) const {
		return x * p.y - y * p.x;
	}
};

vector <Point> a;

int n;

const int INF = (int)1e6;

bool on_line(int i, int j, int k) {
	Point a1 = a[i] - a[j];
	Point b1 = a[k] - a[j];

	return (a1 * b1 == 0);
}

map <set <int>, int> m;

int rec(const set <int>& s) {
	if (s.empty())
		return 0;
	
	if (s.size() == 1) 
		return 1;

	if (m.find(s) != m.end())
		return m[s];

	int ans = INF;

	for (set <int> :: iterator it = s.begin(); it != s.end(); it++) {
		int mask = *it;
		
		vector <int> v(s.begin(), s.end());

		for (int i = 0; i < (int)v.size(); i++)
			if (v[i] & mask)
				v[i] ^= (v[i] & mask);

		set <int> tmp(v.begin(), v.end());

		while (!tmp.empty() && *tmp.begin() == 0)
			tmp.erase(tmp.begin());

		ans = min(ans, rec(tmp) + 1);
	}	

	return (m[s] = ans);
}

int main() {
	freopen("justice.in", "r", stdin);
	freopen("justice.out", "w", stdout);

	int t;

	scanf("%d", &t);

	while (t --> 0) {
		scanf("%d", &n);

		a.resize(n);

		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].x, &a[i].y);

		set <int> s;

		m.clear();

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int mask = 0;

				for (int k = 0; k < n; k++)
					if (on_line(i, j, k))
						mask |= (1 << k);

				s.insert(mask);
			}
		}
		printf("%d\n", rec(s));
	}

	return 0;
}
