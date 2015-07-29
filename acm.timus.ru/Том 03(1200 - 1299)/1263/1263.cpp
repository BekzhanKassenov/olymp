#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;

	cin >> n >> m;

	vector <int> a(n);

	int tmp;

	for (int i = 0; i < m; i++)
		{
			cin >> tmp;

			a[--tmp]++;
		}

	for (int i = 0; i < n; i++)
		{
			float ans = (float(a[i])) / float(m);

			ans *= 100;

			char c = '%';

			printf("%.2f%c\n", ans, c);
		}

	return 0;
}
