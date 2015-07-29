#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 200010;

pair <int, int> a[maxn];
int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in" ,"r", stdin);
	freopen("out", "w", stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;

	priority_queue <int> q;

	long long cur = 0;
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		cur += a[i].first - a[i - 1].first;
		if (cur >= a[i].second) {
			cur -= a[i].second;
			q.push(a[i].second);
		} else {
			if (q.empty())
				ans++;
			else { 
				if (q.top() > a[i].second) {
					cur += q.top() - a[i].second;
					q.pop();
					q.push(a[i].second);
				}
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}