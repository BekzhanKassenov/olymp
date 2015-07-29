#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <int> a(n);
	
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	sort(a.begin(), a.end());

	long long s1 = a[n - 1] * 1ll *  a[n - 2] * 1ll * a[n - 3];
	long long s2 = a[0] * 1l * a[1] * 1ll * a[n - 1];

	cout << max(s1, s2);
}