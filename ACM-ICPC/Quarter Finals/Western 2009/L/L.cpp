/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

struct Point {
 	int x, y;

 	Point() : x(0), y(0) {}

 	Point(int x, int y) : x(x), y(y) {}

 	Point operator - (const Point& a) const {
 		return Point(x - a.x, y - a.y);
 	}

 	int operator * (const Point& a) const {
 		return x * a.x + y * a.y;
 	}

 	bool operator == (const Point& a) const {
 		return (x == a.x && y == a.y);
 	}
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <pair <Point, Point> > a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].F.x >> a[i].F.y >> a[i].S.x >> a[i].S.y;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((a[i].F == a[j].F || a[i].F == a[j].S || a[i].S == a[j].F || a[i].S == a[j].S) && ((a[i].F - a[i].S) * (a[j].F - a[j].S)) == 0)
				ans++;
		}
	}

	cout << ans;

	return 0;
}
