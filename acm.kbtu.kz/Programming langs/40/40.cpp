#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int mn = 2000;

	int tmp;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			{
				cin >> tmp;
				mn = min(tmp, mn);
			}
	cout << mn;
	return 0;
}
