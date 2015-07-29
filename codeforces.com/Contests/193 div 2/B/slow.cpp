#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int a[100500];

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) 
		cin >> a[i];

	long long aa = 0, ab = 0, ans = 0;

	int l = n + 1, r = n + 1;

	for (int i = 1; i <= n; i++) {
		for (int j = i + k; j + k - 1 <= n; j++) {
			aa = 0;
			for (int q = i; q < i + k; q++)
				aa += a[q];

			ab = 0;

			for (int q = j; q < j + k; q++)
				ab += a[q];	

		   	if (aa + ab > ans || (aa + ab == ans && (i < l || (i == l && r < j)))) {
		   		l = i;
		   		r = j;
		   		ans = aa + ab;
		   	}
		}
	}

	cout << l << ' ' << r << endl;


	return 0;
}
