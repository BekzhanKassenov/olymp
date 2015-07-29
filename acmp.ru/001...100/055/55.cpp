#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

template <typename T> 
inline T sqr(T x) {
	return x * x;
}

const double PI = acos(-1.0);

template <typename T> 
struct Point {
 	T x, y;

 	Point() : x(0), y(0) {}

 	Point(T x, T y) : x(x), y(y) {}

 	Point(const Point <T>& p) {
 		*this = p;
 	}

 	Point operator + (const Point <T>& p) const {
 		return Point(x + p.x, y + p.y);
 	}

 	Point operator - (const Point <T>& p) const {
 		return Point(x - p.x, y - p.y);
 	}

 	T operator * (const Point <T>& p) const {
 		return (x * p.y - y * p.x);
 	}

 	bool operator == (const Point <T>& p) const {
 		return (x == p.x && y == p.y);
 	}

 	double sqr_len() {
 		return (sqr(x) + sqr(y));
 	}

 	double len() {
 		return sqrt(sqr_len());
 	}

 	void make_len(double new_len) {
 		double cur_len = len();
 		x *= (new_len / cur_len);
 		y *= (new_len / cur_len);
 	}
};

template <typename T> 
istream& operator >> (istream& c, Point <T>& p) {
	c >> p.x >> p.y;
	return c;
}

template <typename T>
ostream& operator << (ostream& c, const Point <T>& p) {
 	c << p.x << ' ' << p.y << endl;
 	return c;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Point <double> p1, p2;
	cin >> p1 >> p2;
	
	double R, S, area;
	cin >> R >> S;

	if (p1 == p2) {
		area = PI * sqr(R);
	} else {
		Point <double> mid = p1 - p2;

		if (mid.sqr_len() >= 4 * sqr(R)) {
			area = 2 * PI * sqr(R);
		} else {
			double alpha = 2 * acos(mid.len() / (2 * R));
			area = R * R * (2 * PI - alpha + sin(alpha));
		}
	}

	if (area > S)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;	


	return 0;	
}
