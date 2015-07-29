#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

const int maxn = 500;

struct Point {
 	int x, y;

 	Point() : x(0), y(0) {}

 	Point(int x, int y) : x(x), y(y) {}

 	int sqr_len() {
 		return x * 1.0 * x + y * 1.0 * y;
 	}

 	Point operator - (const Point& a) const {
 		return Point(x - a.x, y - a.y);
 	}

 	int operator * (const Point& a) const {
 		return (x * a.y - y * a.x);
 	}

 	void read() {
 		scanf("%d%d", &x, &y);
 	}
} a[maxn];

const double EPS = 1e-9;

int comp(double a, double b) {
	if (fabs(a - b) < EPS)
		return 0;

   	if (a - b >= EPS)
   		return 1;

   	return -1;
}

bool used[maxn][maxn];

int tmp[maxn], uk, n, ans;

int main() {
 	#ifndef ONLINE_JUDGE
 		freopen("in", "r", stdin);
	#endif

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		a[i].read();
		used[i][i] = true;
	}

	double res = 0;

   	for (int i = 0; i < n; i++) {
   		for (int j = i + 1; j < n; j++) {
   			if (!used[i][j] && !used[j][i]) {
   			    uk = 0;

   				for (int k = 0; k < n; k++) {
   					if (k != i && k != j) {
   						Point p1 = a[k] - a[i];
   						Point p2 = a[k] - a[j];

   						if (p1 * p2 == 0)
   							tmp[uk++] = k;
   					}
   				}


   				tmp[uk++] = i;
   				tmp[uk++] = j;

   				ans = 0;

   				for (int i1 = 0; i1 < uk; i1++) {
   					for (int i2 = i1 + 1; i2 < uk; i2++) {
   						ans = max(ans, (a[tmp[i1]] - a[tmp[i2]]).sqr_len());

   						used[tmp[i1]][tmp[i2]] = used[tmp[i2]][tmp[i1]] = true;
   					}
   				}

   				res += sqrt(ans);
   			}
   		}
   	}

   	int pr = (int)(res + 0.5);

   	printf("%d", pr);
}
