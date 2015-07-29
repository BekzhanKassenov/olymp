#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	bool used[100000] = {0};

	int a[10010] = {2, 3, 4, 7, 13, 15, 0};
	int b[10010] = {1, 5, 6, 8, 9, 10, 0};

	for (int i = 0; i < 6; i++)
		{
			used[a[i]] = true;
			used[b[i]] = true;
		}


	used[0] = true;


	int n;

	cin >> n;

	for (int i = 6; i <= n; i++)
		{
			a[i] = b[i - 1] + b[i - 3];
			used[a[i]] = true;

			for (int j = 1; j < 100000; j++)
				{
					if (!used[j])
						{
							used[j] = true;
							b[i] = j;
							break;
						}
				}
		}

	cout << a[n - 1] << endl << b[n - 1];
	
	return 0;	
}
