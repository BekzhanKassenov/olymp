#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int ans = -100000000;
	int z = 0;
	for (int i = 0; i < n; i++)
		{
			int tmp = 0, k;
			for (int j = 0; j < m; j++)
				{
					cin >> k;
					tmp += k;
				}
			if (tmp > ans)
				{
					ans = tmp;
					z  = i + 1;
				}
		}
	cout << z;
	return 0;
}
