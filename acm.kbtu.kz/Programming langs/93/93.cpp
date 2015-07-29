#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp1, tmp2, ans = -1,nmb = -1;

	for (int i = 0; i < n; i++)
		{
			cin >> tmp1 >> tmp2;
			if (tmp2 == 1 && tmp1 > ans)
				{
					ans = tmp1;
					nmb = i + 1;
				}
		}
	if (ans != -1)
		cout << nmb;
	else
		cout << -1;
	return 0;
}
