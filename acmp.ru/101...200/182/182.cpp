#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

ostream& operator << (ostream& stream, pair <int, int> p) {
	stream << p.F << ' ' << p.S;
	return stream;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	pair <int, int> a[3];

	cin >> a[0].F >> a[0].S >> a[1].F >> a[1].S >> a[2].F >> a[2].S;

	for (int i = 0; i < 3; i++) {
		int prev = (i + 2) % 3;
		int next = (i + 1) % 3;

		pair <int, int> v1(a[prev].F - a[i].F, a[prev].S - a[i].S);
		pair <int, int> v2(a[next].F - a[i].F, a[next].S - a[i].S);

		int pr = v1.F * v2.F + v1.S * v2.S;

		if (pr == 0) {
			swap(a[i], a[0]);
			break;
		}
	}

	pair <int, int> v(a[1].F - a[0].F, a[1].S - a[0].S);

	a[2].F += v.F;
	a[2].S += v.S;

	//cerr << a[0] << endl;

	cout << a[2] << endl;

	return 0;
}