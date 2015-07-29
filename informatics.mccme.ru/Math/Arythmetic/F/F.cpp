#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int sum (int n) {
	int res = 1;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res += i;

			if (i * i != n)
				res += n / i;
		}
	}

	return res;
}

bool used[(int)1e5 + 10];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k;

	cin >> k;

	for (int i = 2; i <= k; i++) {
		int s = sum(i); 

		if (s <= k && s != i && !used[i] && !used[s] && sum(s) == i) {
		 	cout << i << ' ' << s << endl;
		 	used[i] = used[s] = true;
		}
	}

	return 0;
}
