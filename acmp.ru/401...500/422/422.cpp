#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (a == 0 || b == 0)
		return a + b;

	return gcd(b, a % b);
}

inline bool cmp (pair <int, int> a, pair <int, int> b) {
	int g = gcd(a.second, b.second);

	int n = a.first * (b.second / g);
	int m = b.first * (a.second / g);

	return (n < m);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	set <pair <int, int> > s;

	vector <pair <int, int> > v;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			pair <int, int> cur(j, i);
			int g = gcd(i, j);
			cur.first /= g;
			cur.second /= g;
			if (s.insert(cur).second)
				v.push_back(cur);
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (vector <pair <int, int> > :: iterator it = v.begin(); it != v.end(); it++) {
	 	cout << it -> first << '/' << it -> second << endl;
	}

	return 0;
}