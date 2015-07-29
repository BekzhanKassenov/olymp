#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()

int res[1000];
int sz = 0;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	while (n --> 0) {
		int x, y;
		cin >> x >> y;

		if (x < 0 || y < 0) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		if (x == 1) {
			if (y != 1)
				cout << "IMPOSSIBLE" << endl;
			else
				cout << "AMBIGUOUS" << endl;

			continue;	
		}

		if (x == y) {
			cout << x << endl;
			continue;
		}

		if (x == 0 && y == 0) {
			cout << 0 << endl;
			continue;
		}

		if (x == 0 || y == 0) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		sz = 0;

		while (y) {
			res[sz++] = y % x;
			y /= x;
		}

		int sum = 0;

		reverse(res, res + sz);

		for (int i = 0; i < sz; i++)
			sum += res[i];

	   	if (sum != x) {
	   		cout << "IMPOSSIBLE" << endl;
	   	} else {
	   		for (int i = 0; i < sz; i++)
	   			cout << res[i] << ' ';

	   		cout << endl;	
	   	}
	}
}
