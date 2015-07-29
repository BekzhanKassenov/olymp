#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100010;

int l[maxn], r[maxn];

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	ios_base :: sync_with_stdio(false);
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];

	int m;

	cin >> m;
	int c;

	for (int i = 0; i < m; i++) {
		cin >> c;
		int ansp = -1;

		for (int j = 0; j < n; j++)
			if (c >= l[j] && c <= r[j] && (ansp == -1 || r[j] - l[j] < r[ansp] - l[ansp]))
				ansp = j;

		if (ansp != -1)
			ansp ++;

		cout << ansp << endl;
	}
}
