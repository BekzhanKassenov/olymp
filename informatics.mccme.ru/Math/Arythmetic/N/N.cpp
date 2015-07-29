#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	bool flag = false;

	for (int i = 2; i * i <= n; i++) {
		int cnt = 0;

		while (n % i == 0) {
			n /= i;
			cnt++;
		}

		if (cnt) {
			if (flag) 
		 		cout << '*';

		 	cout << i;

		 	if (cnt > 1)
		 		cout << '^' << cnt;

		 	flag = true;
		 }
	}

	if (n > 1) {
		if (flag)
			cout << '*';
		cout << n;	
	}

	return 0;
}
