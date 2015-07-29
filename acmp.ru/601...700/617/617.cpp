#include <iostream>
#include <cstdio>

using namespace std;

int used[11][11];
int n, m, k, l;
long long ans;
long long C[11][11];
int freeCells;

void build() {
 	C[0][0] = 1;
 	for (int i = 0; i < 11; i++) {
 	 	C[i][0] = C[i][i] = 1;

 	 	for (int j = 1; j < i; j++)
 	 		C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
 	}
}

void go(int i, int j, int cnt) {
	if (i == n && j == m)
		return;

	for (int k = 0; k < m; k++) {
		used[i][k]++;
		if (used[i][k] == 1)
			freeCells--;
	}

	for (int k = 0; k < n; k++) {
	 	used[k][j]++;
		if (used[k][j] == 1)
			freeCells--;
	}

	if (freeCells >= l)
		go(i + (j + 1) / m, (j + 1) % m, cnt - 1);

}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &k, &l);

	build();
	freeCells = n * m;
	if (k > l)
		swap(k, l);

	go(0, 0, k);

	printf("%I64d\n", ans);
	
	return 0;
}
