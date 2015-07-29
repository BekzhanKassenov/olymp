#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long S(int a, int b, int c) {
	long long p = a + b + c;

	return (p * (p - 2 * a) * (p - 2 * b) * (p - 2 * c));
}

bool ok(int a, int b, int c) {
	return ((a + b >= c) && (a + c >= b) && (b + c >= a));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++) 
		cin >> a[i];

	sort(a.begin(), a.end());

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int ind = (upper_bound(a.begin(), a.end(), a[i] + a[j]) - a.begin());

			for (int k = max(0, ind - 5); k < min(ind, ind + 5); k++) {
				if (k != i && k != j && ok(a[i], a[j], a[k]))
					ans = max(ans, S(a[i], a[j], a[k]));
			}
		}
	}

	if (ans != 0)
		printf("%.3lf", sqrt((ans +.0) / (16.0)));
	else
		puts("0");
			
	return 0;
}
