#include <iostream>
#include <cstdio>

using namespace std;

int read_int() {
	char c;

	do {
		c = getchar();
	} while ((c < '0') || (c > '9'));

	int res = 0;

	do {
		res = res * 10 + c - '0';
		c = getchar();
	while ((c >= '0') && (c <= '9'));

	return res;	
}

struct Point {
 	int x, y;

 	Point() : x(0), y(0) {}

 	Point(int x, int y) : x(x), y(y) {}

 	Point(const Point& a) : x(a.x), y(a.y) {}

 	bool operator * (const Point& a) const {
 		return ((x * a.y - y * a.x) >= 0);
 	}

 	Point operator - (const Point& a) const {
 		return Point(x - a.x, y - a.y);
 	}
} p[200010];

istream& operator >> (istream& in, Point& p) {
	p.x = read_int(), p.y = read_int();
	return in;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n = read_int();

	int x, y;

	for (int i = 0; i < n; i++)
		cin >> p[i];

	int a[2] = {0};

	for (int i = 1; i < n; i++) {
		
	}

}
