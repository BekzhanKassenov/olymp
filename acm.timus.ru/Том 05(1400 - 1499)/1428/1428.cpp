#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b, c;

	cin >> a >> b >> c;

	cout << (1ll << ((c - 1) / a)) << endl << (1ll << ((c - 1) / b)) << endl << 2;

	return 0;
}
