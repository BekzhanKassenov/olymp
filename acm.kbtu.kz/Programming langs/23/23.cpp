#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	float k;

	float ans = 0;

	int pos;

	for (int i = 0; i < n; i++)
		{
			cin >> k;
			k /= 100;

			k *= a[i];

			if (k > ans)
				{
					ans = k;
					pos = i;
				}
		}

	cout << ++pos;
	return 0;
}