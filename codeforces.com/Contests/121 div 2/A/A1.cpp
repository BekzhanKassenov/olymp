#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool is_triangle(int n) {
 	int k = sqrt(n);

 	if ((k * (k + 1)) == n)
 		return true;

 	return false;
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;
	n *= 2;

	int k = sqrt(n);

	for (int i = 1; i <= k; i++) {
		int tmp = n - (i * (i + 1));

		if (tmp > 0 && is_triangle(tmp)) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}
