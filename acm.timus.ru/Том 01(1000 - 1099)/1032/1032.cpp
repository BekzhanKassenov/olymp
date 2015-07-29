#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m[10010];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> a(n + 1);

	int s = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
		s %= n;

		if (s == 0) {
			cout << i << endl;
			for (int j = 1; j <= i; j++)
				cout << a[j] << endl;

			return 0;	
		}

		if (m[s] != 0) {
			cout << i - m[s] << endl;
			for (int j = m[s] + 1; j <= i; j++)
				cout << a[j] << endl;

			break;	
		}

		m[s] = i;
	}

	return 0;

}
