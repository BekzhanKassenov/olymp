#include <iostream>
#include <cstdio>

#define F first
#define S second

using namespace std;

const int INF = 1000 * 1000 * 1000;

int was[12][12][(1 << 11)], dp[12][12][(1 << 11)], pos1, pos2, cnt1, cnt2, used[12][12][(1 << 11)], b[12][12][(1 << 11)], mb[12][12];

pair <int, int> p[12][12][(1 << 11)];

int d, h, w, ans;

char a[12][12][12];

int calc(int x, int y, int mask) {
	if (used[x][y][mask])
		return b[x][y][mask];

	used[x][y][mask] = 1, b[x][y][mask] = -1, cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < d; i++) {
		if ((mask & (1 << i)) > 0)
			continue;
		else
			if (a[i][x][y] == 'B') {
		        	cnt1++;
				pos1 = i;
			} else {
		        	cnt2++;
				pos2 = i;
			}
	}
	if (cnt1 == 1)
		b[x][y][mask] = pos1;
	if (cnt2 == 1)
		b[x][y][mask] = pos2;
	return b[x][y][mask];
}                                   

int rec(int x, int y, int mask) {
	if (was[x][y][mask])
		return dp[x][y][mask];

	was[x][y][mask] = 1, dp[x][y][mask] = INF;

	int gmask = mask;

	if (calc(x, y, mask) != -1)
		gmask |= (1 << calc(x, y, mask));

	if (gmask == (1 << d) - 1) {
		dp[x][y][mask] = 0;
		return 0;
	}

	mb[x][y] = 1;

	if (x + 1 <= h && !mb[x + 1][y])
		dp[x][y][mask] = min(dp[x][y][mask], rec(x + 1, y, gmask) + 1), p[x][y][mask].F = x + 1, p[x][y][mask].S = y;
	if (y + 1 <= w && !mb[x][y + 1])
		dp[x][y][mask] = min(dp[x][y][mask], rec(x, y + 1, gmask) + 1), p[x][y][mask].F = x, p[x][y][mask].S = y + 1;
	if (x - 1 > 0 && !mb[x - 1][y])
		dp[x][y][mask] = min(dp[x][y][mask], rec(x - 1, y, gmask) + 1), p[x][y][mask].F = x - 1, p[x][y][mask].S = y;
	if (y - 1 > 0 && !mb[x][y - 1])
		dp[x][y][mask] = min(dp[x][y][mask], rec(x, y - 1, gmask) + 1), p[x][y][mask].F = x, p[x][y][mask].S = y - 1;

	return dp[x][y][mask]; 
}               

void print(int x, int y, int mask) {
	if (calc(x, y, mask) != -1) {
		int gmask = mask;
		gmask |= (1 << calc(x, y, mask));
		if (gmask == (1 << d) - 1) {
			cout << calc(x, y, mask);
			return;
		}
		cout << '(' << calc(x, y, mask) << ':';
		if (p[x][y][mask].F == x + 1)
			cout << 'D';
		if (p[x][y][mask].F == x - 1)
			cout << 'U';
		if (p[x][y][mask].S == y + 1)
			cout << 'R';
		if (p[x][y][mask].S == y - 1)
			cout << 'L';
		print(p[x][y][mask].F, p[x][y][mask].S, gmask);
		cout << ')';
		return;
	}
	if (p[x][y][mask].F == x + 1)
		cout << 'D';
	if (p[x][y][mask].F == x - 1)
		cout << 'U';
	if (p[x][y][mask].S == y + 1)
		cout << 'R';
	if (p[x][y][mask].S == y - 1)
		cout << 'L';
	print(p[x][y][mask].F, p[x][y][mask].S, mask);
}      

int main() {
	freopen("image.in", "r", stdin);
	freopen("image.out", "w", stdout);
	cin >> d >> h >> w;
	for (int i = 0; i < d; i++) {
		for (int j = 1; j <= h; j++)
			for (int k = 1; k <= w; k++)
				cin >> a[i][j][k];
	}

	ans = rec(1, 1, 0);

	cout << ans << endl;
	
	print(1, 1, 0);
}