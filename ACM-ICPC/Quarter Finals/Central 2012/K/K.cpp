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

 	Point() { }

 	Point(int x, int y) : x(x), y(y) { }

 	Point(const Point& p) {
 		*this = p;
 	}

 	Point operator + (const Point& p) const {
 		return Point(x + p.x, y + p.y);
 	}

 	Point operator - (const Point& p) const {
 		return Point(x - p.x, y - p.y);
 	}
};

int the_leftmost_position(const Point& l, const Point& r) {
	if (r.y <= l.y)
		return 0;

	Point temp = r - l;

	double res = ((temp.x + .0) * r.y) / (temp.y + .0);
	int ans = ceil(res);

	return max(ans, 0);

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	return 0;
}
