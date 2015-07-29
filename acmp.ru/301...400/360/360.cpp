#include <cstdio>

using namespace std;

/*
    All possible variants:
    --   |   --  |        |
     |  --   |   --  ---  |
                          | 
*/

int dx1[6] = { 0,  0,  0, 0,  0, -1};
int dy1[6] = {-1, -1,  1, 1,  1,  0};
int dx2[6] = { 1, -1,  1,-1,  0,  1};
int dy2[6] = { 0,  0,  0, 0, -1,  0};

const int maxn = 2010;
int a[maxn][maxn], n;	

inline bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
	   		scanf("%d", &a[i][j]);
	}

	int ans = -100 * 3000 * 3000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 6; k++) {
				int tx1 = i + dx1[k];
				int ty1 = j + dy1[k];

				int tx2 = i + dx2[k];
				int ty2 = j + dy2[k];

				if (ok(tx1, ty1) && ok(tx2, ty2)) {
					int t = a[i][j] + a[tx1][ty1] + a[tx2][ty2];
					if (t > ans)
						ans = t;
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}

