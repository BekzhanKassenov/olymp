#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp = 0, ans1 = 0, ans2 = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			{
				cin >> tmp;
				if (i == j)
					ans1 += tmp;
				if (i + j + 1 == n)
					ans2 += tmp;
			}
	cout << ans1 << ' ' << ans2;
	return 0;
}
