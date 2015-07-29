#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;

	cin >> n;

	vector <int> a(n + 1);

	vector <int> v;

	int ans = 0;

	for (int i = 0; i <= n; i++)
		a[i] = i;

	do {
		int tmp = 0;

		for (int i = 0; i <= n; i++)
			tmp += (i ^ a[i]);

		if (tmp > ans) {
			ans = tmp;
			v = a;
		}	

	} while (next_permutation(a.begin(), a.end()));	

	cout << ans << endl;

	for (int i = 0; i <= n; i++)
		cout << v[i] << ' ';

	return 0;	
}
