#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	unsigned int n;

	cin >> n;

	vector <int> a;

	while (n)
		{
			a.push_back(n & 1);
			n >>= 1;
		}

	bool flag = false;

	for (int i = 0; i < (int)a.size() - 1; i++)
		{
			if (a[i] == 1 && a[i + 1] == 0)
				{
					a[i] = 0;
					a[i + 1] = 1;
					flag = true;
					break;
				}
		}

	if (!flag)
		{
			a[a.size() - 1] = 0;
			a.push_back(1);
		}	

	for (int i = 0; i < (int)a.size(); i++)
		{
			if (a[i] == 1)
				n += (1 << i);
		}

	cout << n;

	return 0;
}
