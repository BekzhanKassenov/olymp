#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int n;
long long sum, s, ans;
map <long long, int> Map;
int a[200010];

int main() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		Map[sum]++;
	}

	sum = 0;
	for (int i = 1; i <= n; i++) {
		ans += Map[s + sum];
		sum += a[i];
		Map[sum]--;
	}
	cout << ans;
	return 0;
}