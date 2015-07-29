#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>


using namespace std;

const int N = 22000;

const double INF = 1e100;

long long sqr(int x) {
	return 1ll* x * x;
}

struct point {
	int x, y;
	point() {}
	point(int _x, int _y): x(_x), y(_y) {}
	long long operator*(const point& r) const {
		return 1ll*x*r.y - 1ll*y*r.x;
	}
	point operator-(const point& r) const  {
		return point(x-r.x, y-r.y);
	}
	double slope() const {
		if (y == 0 && x == 0) return -INF;
		if (x == 0) return INF;
		return 1.0 * y / x;
	}
	long long r() const {
		return 1ll * x * x + 1ll * y * y;
	}
};

bool cmp(const point&l, const point& r) {
	if (l * r < 0) return 0;
	if (l * r > 0) return 1;
	return l.r() < r.r();
}


point p[N], s[N];

int n;

int main() {
	freopen("in", "r", stdin);
	freopen("stup.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0 ; i < n ; i ++) {
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	for (int i = 0 ; i < n ; i ++) {
		if (p[0].x > p[i].x || (p[0].x == p[i].x && p[0].y > p[i].y))
			swap(p[0], p[i]);
	}
	for (int i = n - 1 ; i >= 0 ; i --)
		p[i] = p[i] - p[0];
		
	sort(p, p + n, cmp);
	int sn = 0;
	
	for (int i = 0 ; i < n ; i ++) {
		if (i < 2) {
			s[sn ++] = p[i];
			//cout << "Added " << sn - 1 << " " << p[i].x << ' ' << p[i].y << endl;
		}
		else {
			while (sn >= 2 && (s[sn-1]-s[sn-2]) * (p[i] - s[sn-1]) <= 0)
				sn --;
			s[sn ++] = p[i];
			//cout << "Added " << sn - 1 << " " << p[i].x << ' ' << p[i].y << endl;
		}
	}
	double perimeter = 0.0;
	s[sn] = s[0];
	for (int i = 0 ; i < sn ; i ++) {
		//printf("%d %d\n", s[i].x, s[i].y);
		perimeter += sqrt( sqr(s[i+1].x-s[i].x) + sqr(s[i+1].y-s[i].y));
	}
	
	printf("%.12lf\n", perimeter);
	
	
	
	return 0;
}