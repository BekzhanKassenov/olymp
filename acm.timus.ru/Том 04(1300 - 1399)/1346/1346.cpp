#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int x, y;

	cin >> x >> y;

	int n = abs(y - x + 1);

	vector <int> a;

	for (int i = 0; i < n; i++)
		{
			int x;

			cin >> x;

			if (a.empty())
				a.push_back(x);
			else
				if (x != a.back())
					a.push_back(x);	
		}

	n = a.size();

	int ans = 1;

	for (int i = 1; i < n - 1; i++)
		{
			if (a[i] > a[i - 1] && a[i] > a[i + 1])
				if (!(i < n - 2 && a[i + 2] > a[i + 1]))
					{
						cout << i << endl;
						ans++;
					}

			if (a[i] < a[i - 1] && a[i] < a[i + 1])
				if (!(i < n - 2 && a[i + 2] < a[i + 1]))
					{
						cout << i << endl;
						ans++;
					}
		}

	cout << ans;	

	return 0;
}
