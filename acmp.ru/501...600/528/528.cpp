#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;

	cin >> n >> k;

	long long res = n, cur = n - 1;

	for (int i = 1; i < k; i++) {
		cur += n - 2;
		res += cur;
	}

	cout << res << endl;
	
	return 0;
}
