/****************************************
**         Solution by NU_02           **
****************************************/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0asd
#define y1 y1asd
#define yn enasd
#define j0 j0asd
#define j1 j1asd
#define jn jnasd

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

struct Point {
 	int x, y;

 	Point() : x(0), y(0) {}

 	Point(int x, int y) : x(x), y(y) {}

 	Point(const Point& p) {
 		*this = p;
 	}

 	Point operator - (const Point& a) const {
 		return Point(x - a.x, y - a.y);
 	}

 	Point operator + (const Point& a) const {
 		return Point(x + a.x, y + a.x);
 	}

 	int operator * (const Point& a) const {
 		return (x * a.y - y * a.x);
 	}

 	bool operator != (const Point& a) const {
 		return (x != a.x || y != a.y);
 	}

 	bool operator == (const Point& a) const {
 	 	return (x == a.x && y == a.y);
 	}

 	int dist() {
 		return sqr(x) + sqr(y);
 	}
};

vector <Point> convex_hull(const vector <Point>& a) {
	int n = a.size();
	vector <bool> used(n);
	vector <Point> ans;

	if (n <= 3)
		return a;
	int pos = 0;

	for (int i = 1; i < n; i++) {
	 	if (a[i].x < a[pos].x || (a[i].x == a[pos].x && a[i].y < a[pos].y))
	 		pos = i;
	}

	used[pos] = true;

	ans.push_back(a[pos]);

	while (true) {
		int ptr = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] != ans.back() && !used[i]) {
				if (ans.size() > 3 && ptr == -1)
					ptr = pos;

				if (ptr == -1)
					ptr = i;
				else {
					int q = (a[ptr] - ans.back()) * (a[i] - ans.back());
					if (q < 0 || (q == 0 && (a[ptr] - ans.back()).dist() > (a[i] - ans.back()).dist()))
						ptr = i;
				}
		   	}
		}

		if (ptr == pos || ptr == -1)
			break;

		used[ptr] = true;
		ans.push_back(a[ptr]);
	}

	return ans;
}

int area_all(const vector <Point>& a) {
	int ans = 0;

	for (int i = 1; i < (int)a.size(); i++) {
	 	ans += ((a[i] - a[0]) * (a[i - 1] - a[0]));
	}
	return abs(ans);
}

int area(const Point& a, const Point& b, const Point& c) {
	return abs((a - c) * (b - c));
}

int main() {
	#ifdef Local
	//	freopen("in", "r", stdin);
	#endif

	int n, m;
	cin >> n >> m;

	vector <Point> a(m);
	vector <Point> b;
	for (int i = 0; i < m; i++)
		cin >> a[i].x >> a[i].y;

	b = convex_hull(a);

	while (b.size() > n){
	 	int index = -1, arinf= 1000000000;
	 	int a1, b1, c1;
	 	for (int i = 0; i < b.size(); ++i){
	 		a1 = i-1; b1 = i; c1 = i+1;
	 		
	 		if (a1 < 0) 
	 			a1 = b.size()-1;
	 		
	 		if (c1 >= b.size()) 
	 			c1 = 0;
	 		Point aaa = b[a1], bbb = b[b1], ccc = b[c1];
	 		
	 		int ar = area(aaa, bbb, ccc);
	 		
	 		if (arinf > ar){
	 			index = i;
	 			arinf = ar;
	 		}
	 	}
	 	Point tp = b[index];
	 	for (int i = 0; i < a.size(); ++i){
	 		if (tp == a[i]){
	 			a.erase(a.begin()+i);
	 			break;
	 		}
	 	}
	 	b = convex_hull(a);

	}       
	//for (int i = 0; i < (int)b.size(); i++)
	//	cout << b[i].x << ' ' << b[i].y << endl;
	cout << double(area_all(b)) / 2.0 << endl;	

	return 0;
}
