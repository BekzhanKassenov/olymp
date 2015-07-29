#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	vector <int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int cnt;

	cin >> cnt;

	int penalty = 0;

	int mx = 0;

	int m;

	cin >> m;

	while (m--)
		{
			int tmp;

			bool flag = true;

			int balls = 0;

			for (int i = 0; i < n; i++)
				{
					cin >> tmp;

					if (tmp == 0)
						flag = false;
					else
						balls += a[i];
					
				}

			if (flag)
				balls += cnt;

			balls -= penalty;

			penalty += 2;

			mx = max(mx, balls);

			cout << mx << endl;
		}

}
