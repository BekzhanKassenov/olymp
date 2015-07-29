#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				{
					int x;
					cin >> x;
					if (x == 0)
						{
							cout << i + 1 << ' ' << j + 1;
							return 0;
						}
				}
		}
}
