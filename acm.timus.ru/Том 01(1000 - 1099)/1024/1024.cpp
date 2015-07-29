#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> a;
vector <bool> used;

int dfs(int v, int gl) {
	used[v] = true;

	if (!used[a[v]])
		return dfs(a[v], gl + 1);

	return gl;	
}

int gcd(int a, int b) {
	if (!a || !b)
		return a + b;

	return gcd(b % a, a);	
}

int lcm(int a, int b) {
	if (!a || !b)
		return a + b;

	return (a / gcd(a, b) * b);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	a.resize(n);
	used.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (!used[i])
			ans = lcm(ans, dfs(i, 1));
	}

	cout << ans;

	return 0;
}