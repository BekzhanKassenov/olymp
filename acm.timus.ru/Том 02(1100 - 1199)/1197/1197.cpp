#include <iostream>
#include <cstdio>

using namespace std;

int u[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int d[8] = {2, 1,-1,-2,  -2, -1,  1,  2};

int main()
{
	int n;

	cin >> n;

	char a, b;

	for (int i = 0; i < n; i++)
		{
			cin >> a >> b;

			a -= 'a' - 1;

			b -= '0';

			int ans = 0;

			for (int j = 0; j < 8; j++)
				{
					int x, y;
					
					x = a + u[j];
					
					y = b + d[j];

					if (x >= 1 && x <= 8)
						if (y >= 1 && y <= 8)
							ans++;
				}

			cout << ans << endl;	
		}
	return 0;
}
