#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <vector <int> > g(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> g[i][j];

	vector <int> k(n);

	for (int i = 0; i < n; i++)
		cin >> k[i];

	int a = 0, b = 0, t = 10000000;

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				{
					if (k[i] == 0 && k[j] == 1)
						{
							if (g[i][j] < t)
								{
									a = i;
									b = j;
									t = g[i][j];
								} 
						}
				}
		}

  	cout << a + 1 << ' '  << b + 1;
  	return 0;
}
