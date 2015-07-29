#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

int main() {
	int n;
	cin >> n;
	vector <pair <int, int> > a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;

	int k = a[0].first;
	int pos = 0;
	int ans = 0;
	while (pos < n) {
		while (pos < n && a[pos].first < k)
			pos++;

		if (pos < n) {
			ans = max(ans, a[pos].second);
			k++;
		}
	}
	cout << ans;

	return 0;
}