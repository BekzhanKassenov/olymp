#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	int pos = 0;

	vector <pair <int, bool> > b(2 * n);

	for (int i = 0; i < n; i++)
		{
			int x;
			
			cin >> x;

			b[pos++] = MP(x, true);

			cin >> x;

			b[pos++] = MP(x, false);
		}

	sort(b.begin(), b.end());

	int gl = 0;

	int ans = 0;

	for (int i = 0; i < 2 * n - 1; i++)
		{
			if (b[i].S)
				gl++;
			else
				gl--;

			if (gl > 0)
				ans += b[i + 1].F - b[i].F;
		}

	cout << ans;

	return 0;
}
