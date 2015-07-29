#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool check(int l, int k)
{
	vector <int> d(k + 1);

	d[0] = 0;

	d[1] = 1;

	for (int i = 2; i <= k; i++)
		{
			d[i] = 0;
			for (int j = 1; j <= l; j++)
				{
					if (i - j >= 0)
						if (d[j] == 0)
							{
								d[i] = 1;
								break;
							}

				}
		}

	if (d[k] == 1)
		return false;

	return true;
}

int main()
{
	int l, k;

	cin >> k;

	cout << check(2, 12422) << endl;

	/*for (int l = 2; l <= 5; l++)
		if (check(l, k))
			cout << l; */

  	return 0;
}

