#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n, m;
	
	cin >> n >> m;
	
	vector <int> k(m);
	
	for (int i = 0; i < m; i++)
		cin >> k[i];

	vector <bool> w(n + 1, false);
	w[0] = 1;
	w[1] = 0;

	sort(k.begin(), k.end());
	
	for (int i = 2; i <= n; i++)
		{
			w[i] = 0;
			for (int j = 0; j < m; j++)
				{
					if (i - k[j] >= 0 && w[i - k[j]] == 0)
						{
							w[i] = 1;
							break;
						}
				}
			//cout << w[i] << ' ';
		}

	if (w[n])
		cout << '1';
	else
		cout << '2';

	return 0;
}