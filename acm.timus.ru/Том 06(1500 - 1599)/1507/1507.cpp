#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;

int n;

vvb ed;

vvb operator * (const vvb& a, const vvb& b) {
	vvb ans(n, vb(n, false));

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
		 	for (int k = 0; k < n; k++)
		 		ans[i][j] = (ans[i][j] | (a[i][k] & b[k][j]));

	return ans;
}

vvb operator + (const vvb& a, const vvb& b) {
	vvb ans(n, vb(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			ans[i][j] = (a[i][j] || b[i][j]);
	}

	return ans;
}

vvb bin_pow(const vvb& a, int st) {
	if (st == 0) {

		vvb ed(n, vb(n));

		for (int i = 0; i < n; i++)
			ed[i][i] = true;

		return ed;
	}

	if (st & 1) {
	 	vvb tmp = bin_pow(a, st - 1);

	 	return tmp * a;
	} else {
		vvb tmp = bin_pow(a, st >> 1);

		return tmp * tmp;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> n;

	vvb a(n, vb(n, false));

	int x;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			a[i][j] = (x > 0);
		}
	}

	vvb st = bin_pow(a, n * (n - 1));

	vvb ans = st;

	for (int i = (n * (n - 1) + 1); i <= (n * (n + 1)); i++) {
		st = st * a;
		ans = ans + st;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ans[i][j] == false) {
				cout << "No";
				return 0;
			}

	cout << "Yes" << endl;

	return 0;
}