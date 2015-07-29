#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
 	long long x, y;

 	Point() : x(0), y(0) {}

 	Point(long long x, long long y) : x(x), y(y) {}

 	Point(const Point& a) {
 		*this = a;
 	}

 	Point operator - (const Point& a) const {
 		return Point(x - a.x, y - a.y);
 	}

 	long long operator * (const Point& a) const {
 		return (x * a.y - y * a.x);
 	}
};

istream& operator >> (istream& in, Point& p) {
 	in >> p.x >> p.y;
 	return in;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <Point> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

   	for (int i = 1; i < n; i++) {
   		Point cur = a[i] - a[0];

   		int cnt1 = 0, cnt2 = 0;

   		for (int j = 1; j < n; j++) {
   			if (j != i) {
   				Point tmp = a[j] - a[0];

   				if (tmp * cur > 0)
   					cnt1++;
   				else
   					cnt2++;	
   			}
   		}

   		if (cnt1 == cnt2) {
   			cout << 1 << ' ' << i + 1 << endl;
   			return 0;
   		}
   	}

   	return 0;
}
