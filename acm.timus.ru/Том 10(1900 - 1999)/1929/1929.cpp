#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	set <int> a;

	for (int i = 0; i < m; i++)
		{
			int tmp;

			cin >> tmp;

			a.insert(tmp);
		}

	int ans = 0;

	for (int i = 2; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
				{
					int cnt = (a.find(1) != a.end()) + (a.find(i) != a.end()) + (a.find(j) != a.end());
					
					if (!cnt)
						continue;

					if (a.size() - cnt >= ((n - 1) / 3))
						ans++;
				}
		}

	cout << ans;
}	
