#include <iostream>
#include <cstdio>

using namespace std;

int a[500], n;
bool can[10000100];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	can[0] = true;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int pos = 1000010 - 1; pos >= 0; pos--)
			if (can[pos])
				can[pos + a[i]] = true;
	}

	for (int i = 0; i < 1000010; i++)
		if (!can[i]) {
			cout << i;
			return 0;
		}

}
