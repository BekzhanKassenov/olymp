#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 10010;

int t[maxn], n, k, ans, x;

inline void upd(int pos) {
	for (int i = pos; i < n; i |= (i + 1))
		t[i]++;
}

inline int get(int pos) {
	int res = 0;

	for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
		res += t[i];

	return res;	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> k;

	while (k--) {
		memset(t, 0, sizeof t);

		for (int i = 0; i < n; i++) {
			cin >> x;
			ans += get(n - 1) - get(x - 1);
			upd(x - 1);
		}
	}

	cout << ans;
	return 0;
}