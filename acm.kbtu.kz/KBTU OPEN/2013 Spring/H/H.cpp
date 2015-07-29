#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct Point {
	int x, y;

	Point() : x(0), y(0) {}

	Point(int x, int y) : x(x), y(y) {}

	Point operator - (const Point& p) const {
		return Point(x - p.x, y - p.y);
	}

	int operator * (const Point& p) const {
		return x * p.y - y * p.x;
	}
};

int dp[1 << 16];

const int INF = (int)1e6;

vector <Point> a;

int n;

bool on_line(int i, int j, int k) {
	Point a1 = a[i] - a[j];
	Point b1 = a[k] - a[j];

	return (a1 * b1 == 0);
}

int rec(int mask) {
	if (dp[mask] < INF)
		return dp[mask];

	if (mask == 0)
		return 0;

   	if (__builtin_popcount(mask) <= 2)
   		return 1;

   	for (int i = 0; i < n; i++)
   		for (int j = i + 1; j < n; j++) {
   			if ((mask & (1 << i)) && (mask & (1 << j))) {
   				int tmpm = mask;

   				for (int k = 0; k < n; k++)
   					if ((mask & (1 << k)) && on_line(i, j, k))
   						tmpm -= (1 << k);

   				dp[mask] = min(dp[mask], rec(tmpm) + 1);
   			}
   		}

   	return dp[mask];
}
	
int main() {
	freopen("justice.in", "r", stdin);
	freopen("justice.out", "w", stdout);

	int t;

	scanf("%d", &t);

	while (t --> 0) {
		scanf("%d", &n);

		a.resize(n);

		memset(dp, INF, sizeof dp);

		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].x, &a[i].y);

		int mask = (1 << n) - 1;

		printf("%d\n", rec(mask));
	}

	return 0;
}
