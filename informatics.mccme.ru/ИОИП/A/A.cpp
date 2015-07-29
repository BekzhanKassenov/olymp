#include <iostream>
#include <cstdio>

using namespace std;

int a[1010][1010];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	char k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> k;
			if (k == '.')
				a[i][j] = 1;
		}
	}
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans += (a[i][j] ? (a[i + 1][j] + a[i][j + 1]) : 0); 
		}
	}

	cout << ans;

	return 0;
}   
