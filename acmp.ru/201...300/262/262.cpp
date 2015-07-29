#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int x;
	priority_queue <int, vector <int>, greater <int> > q;

	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}

	long long ans = 0;

	for (int i = 0; i < n - 1; i++) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		ans += a + b;
		q.push(a + b);
	}

	printf("%.2lf", ans * 0.05);

	return 0;
}
