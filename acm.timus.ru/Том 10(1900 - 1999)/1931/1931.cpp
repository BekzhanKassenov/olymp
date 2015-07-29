#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;
	
	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int ans = 0, uk = 0;

	vector <int> sr(n, 0);

	for (int i = 1; i < n; i++)
		{
			sr[i]++;
			sr[uk]++;

			if (a[i] < a[uk])
				uk = i;
		}

	for (int i = 0; i < n; i++)
		if (sr[ans] < sr[i])
			{
				ans = i;
			}

	cout << ans + 1;

	return 0;
}
