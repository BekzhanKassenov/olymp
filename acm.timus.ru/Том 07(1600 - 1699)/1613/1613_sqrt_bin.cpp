#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define all(x) (x).begin(), (x).end()

const int maxn = 100000;

int a[maxn];

int main() {          
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	ios_base :: sync_with_stdio(false);

	int n;
	                           
	cin >> n;

	int len = sqrt(n + .0) + 2;

	vector <vector <int> > b(len + 1, vector <int> (len));

	for (int i = 0; i < n; i++) {
		cin >> a[i];

		b[i / len][i % len] = a[i];
	}

	for (int i = 0; i < len + 1; i++)
		sort(all(b[i]));

	int val, l, r, m;

	cin >> m;

	for (int i = 0; i < m; i++) {
	 	cin >> l >> r >> val;

	 	l--, r--;

	 	bool ans = false;

	 	if (r - l <= 2 * len + 4) {
	 	 	for (int j = l; j <= r && !ans; j++)
	 	 		ans = (a[j] == val);
	 	} else {
	 		while (!ans && l % len != 0)
	 			ans = (a[l++] == val);

	 	   	while (!ans && r % len != 0)
	 	   		ans = (a[r--] == val);

	 	   	ans |= (a[l] == val || a[r] == val);

	 	   	for (int t_l = l / len, t_r = r / len; !ans && t_l < t_r; t_l++) 
	 	   		ans = binary_search(all(b[t_l]), val);
	 	}  	

	 	putchar(ans ? '1' : '0');
	}

	return 0;
}
                               