#include <iostream>
#include <cstdio>

using namespace std;

int table[6 * 6 * 6 * 6 + 1], ans[4];

void make() {
	char c = getchar();
	int hash = 0;
	for (int i = 0; i < 4; i++) {
		c = getchar();
		hash = hash * 6 + c - 'a';
	}
	table[hash]++;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		make();


	for (int i = 0; i < 36 * 36 + 1; i++) {
		for (int j = 0; j < i; j++) {
			int cnt = 0;
			int ti = i, tj = j;

			for (int k = 0; k < 4; k++) {
				if (ti % 6 != tj % 6)
					cnt++;

				ti /= 6;
				tj /= 6;
			}
			ans[cnt - 1]++;
		}
	}
	for (int i = 0; i < 4; i++)
		cout << ans[i] << ' ';
	cout << endl;	
}
