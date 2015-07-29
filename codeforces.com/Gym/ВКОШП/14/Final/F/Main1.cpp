/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "polygon"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-8;
const double pi = acos(-1.0);
const int maxn = 2010;

template <typename T>
inline T sqr(T n) {
	return (n * n);
}

struct Point {
 	double x, y;

 	Point() { } 

 	Point(double x, double y) : x(x), y(y) { }

 	Point(const Point& p) {
 		*this = p;
 	}

 	Point operator - () const { 
 		return Point(-x, -y);
 	}

 	Point operator - (const Point& p ) const {
 		return Point(x - p.x, y - p.y);
 	}

 	Point operator + (const Point& p) const {
 		return Point(x + p.x, y + p.y);
 	}

 	Point operator / (double k) const {
 		return Point(x / k, y / k);
 	}

 	double operator * (const Point& p) const {
 		return x * p.y - y * p.x;
 	}

 	double operator ^ (const Point& p) const {
 		return x * p.x + y * p.y;
 	}

 	double len() const {
 		return (sqrt(sqr(x) + sqr(y)));
 	}

 	void read() {
 		scanf("%lf%lf", &x, &y);
 	}

 	void print() const {
 		cout << x << ' ' << y << endl;
 	}
};

int comp(double a, double b) {
	if (fabs(b - a) < EPS)
		return 0;
	else if (b - a > 0)
		return -1;
	return 1;	
}

Point a[maxn], b[maxn];
int n, m;

Point bin(const Point& p1, const Point& p2, double rad) {
	Point l(p1), r(p2);

	if (l.len() > r.len())
		swap(l, r);

	
	for (int i = 0; i < 30; i++) {
		Point mid = (l + r) / 2.0;

		double ln = mid.len();

		if (comp(ln, rad) == 0)
			return mid;

		if (comp(ln, rad) == -1)
			l = mid;
		else
			r = mid;	
	}

	return l;
}

Point ans1, ans2;
double ansalpha, ansbeta;
double mx = -1.0, mn = 360.0;
bool used;

double to_deg(double ang) {
	return (180.0 * ang) / pi;
}

void check(const Point& cur) {
 	used = false;

 	double d = cur.len();

 	ansalpha = ansbeta = 2 * pi;

 	for (int i = 0; i < n; i++) {
 		double mx = max(a[i].len(), a[(i + 1) % n].len());
 		double mn = min(a[i].len(), a[(i + 1) % n].len());

 		if (comp(mn, d) < 0 && comp(mx, d) > 0) {
 			Point temp = bin(a[i], a[(i + 1) % n], d);

 			if (!used) {
 				ans1 = ans2 = temp;
 				ansalpha = atan2(cur * temp, cur ^ temp) + pi;  
 				
 				ansbeta = 2.0 * pi - ansalpha;

 				//cout << "CUR ";
 			//	cur.print();
 				//cout << "TEMP ";
 			//	temp.print();
 				//cout << "ASD" << (cur * temp) << ' ' << (cur ^ temp) << endl;
 				
 				mx = max(mx, ansalpha);
 				mn = min(mn, ansbeta);
 				used = 1;
 			} else {
 				ansalpha = atan2(cur * temp, cur ^ temp) + pi;  
 				ansbeta = 2.0 * pi - ansalpha;
 				mx = max(mx, ansalpha);
 				mn = min(mn, ansbeta);
 			}
 			//temp.print();
 		}	 
 	}
}


int main() {
	freopen(File".in", "r", stdin);
	freopen(File".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		a[i].read();
		a[i] = a[i] - a[0];
	}

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		b[i].read();
		b[i] = b[i] - a[0];
		check(b[i]);

		printf("%14lf %14lf\n", to_deg(ansalpha), to_deg(ansbeta));
	}

	return 0;
}
