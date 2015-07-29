#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10010;
const int INF = (int)1e9;

int dp_max[maxn], dp_min[maxn], p[maxn], w[maxn], e, f, n;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> e >> f;

	f -= e;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i] >> w[i];

	for (int i = 0; i < maxn; i++) {
		dp_max[i] = -INF;
		dp_min[i] = INF;
	}

	dp_max[0] = dp_min[0] = 0;

	for (int i = 1; i < maxn; i++) {
		for (int j = 0; j < n; j++) {
			if (i - w[j] >= 0) {
				dp_max[i] = max(dp_max[i], dp_max[i - w[j]] + p[j]);
				dp_min[i] = min(dp_min[i], dp_min[i - w[j]] + p[j]);
			}
		}
	}

	if (dp_max[f] < 0 || dp_min[f] == INF)
		cout << "This is impossible." << endl;
	else
		cout << dp_min[f] << ' ' << dp_max[f] << endl;

	return 0;	
}
