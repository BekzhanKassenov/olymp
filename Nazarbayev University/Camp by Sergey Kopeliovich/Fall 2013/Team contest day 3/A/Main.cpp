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

const double PI = acos(-1.0);

struct Point {
 	double x, y;

 	Point() : x(x), y(y) {}

 	Point(double x, double y) : x(x), y(y) {}

 	Point(const Point& p) {
 		*this = p;
 	}

 	Point operator + (const Point& p) const {
 		return Point(x + p.x, y + p.y);
 	}

 	Point operator - (const Point& p) const {
 		return Point(x - p.x, y - p.y);
 	}

 	double len() {
 		return sqr(x) + sqr(y);
 	}

 	pair <double, double> get_angle(const Point& p, double R) const {
 		double dist = sqrt((p - *this).len()) / 2.0;

 		double alpha = acos(dist / R);

 		double beta = atan2(p.y - y, p.x - x);

 		//cout << "A " << alpha << ' ' << beta << endl;

 		return MP(beta - alpha, beta + alpha);
 	}
};

Point a[3000];

bool cmp(const pair <double, bool>& p1, const pair <double, bool>& p2) {
	if (fabs(p1.F - p2.F) < EPS) {
		if (p1.S == false && p2.S == true)
			return true;

		return false;
	}

	if (p1.F - p2.F < 0)
		return true;

	return false;	
}

int main() {
	#ifdef Local
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	int n;
	double r;

	while ((cin >> n >> r) && n) {
		for (int i = 0; i < n; i++)
			cin >> a[i].x >> a[i].y;

		int ans = 0;

		for (int i = 0; i < n; i++) {
			vector <pair <double, bool> > scanline;
			for (int j = 0; j < n; j++) {
				if (i == j || (a[i] - a[j]).len() > sqr(2 * r))
					continue;

				pair <double, double> angle = a[i].get_angle(a[j], r);

				if (angle.F < 0 && angle.S < 0) {
					angle.F += 2 * PI;
			   		angle.S += 2 * PI;
			   	}
			   		
			   	if (angle.F > angle.S)
			   		swap(angle.F, angle.S);

			   	if (angle.S >= 2 * PI) {
			   		scanline.push_back(MP(angle.F, false));
			   		scanline.push_back(MP(2 * PI, true));
			   		scanline.push_back(MP(0, false));
			   		scanline.push_back(MP(angle.S - 2 * PI, true));
			   	} else {
			   		scanline.push_back(MP(angle.F, false));
			   		scanline.push_back(MP(angle.S, true));
			   	}
			}
			sort(all(scanline), cmp);

			int cnt = 0;

			for (int j = 0; j < (int)scanline.size(); j++) {
			//	cout << scanline[j].F << ' ' << scanline[j].S << endl;
				if (!scanline[j].S)
					cnt++;
				else
					cnt--;	

				ans = max(ans, cnt);	
			}

			//cout << endl;
		}

		ans++;

		cout << "It is possible to cover " << ans << " points." << endl;
	}

	return 0;
}
