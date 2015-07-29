#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

bool used[1000012];

int sum(int n) {
	
	int ans = 1;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
		 	ans += i;

		 	if (i * i != n)
		 		ans += n / i;
		}

	return ans;	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;

	bool flag = false;

	for (int i = n; i <= m; i++) {
		int tmp = sum(i);

		if (sum(tmp) == i && tmp >= n && tmp <= m && !used[tmp] && !used[i] && tmp != i) {
			printf("MP(%d, %d),\n", i, tmp);
			used[i] = used[tmp] = true;
			flag = true;
		}
	}


	if (!flag)
		cout << "Absent" << endl;

  	return 0;
}