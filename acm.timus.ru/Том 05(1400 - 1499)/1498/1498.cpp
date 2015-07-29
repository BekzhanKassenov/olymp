#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, m, l, xs, ys, xf, yf;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	scanf("%d%d%d%d%d%d%d", &n, &m, &l, &xs, &ys, &xf, &yf);

	if (abs(xs - xf) + abs(ys - yf) < l) 
		cout << 0;

	if (n == 1 || m == 1)
		cout << abs(xs - xf) + abs(ys - yf) + 1;
	else
		cout << l + 1;

	return 0;	
}
