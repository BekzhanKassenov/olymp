#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;

	cin >> n;

	n = 2 * n + 1;

	vector <vector <int> > a(n, vector <int> (n, -1));

	int nmb = 0;

	for (int i = 0; i < n; i++)
		a[i][i] = nmb;

	nmb ++;

	for (int i = 1; i < n; i++)
		{
			int tmp = i, j = 0;
			while (tmp >= 0 && j < n)
				{
					if (a[tmp][j] == -1)
						a[tmp][j] = nmb;

					tmp--;
					j++;
				}
			nmb = nmb % n + 1;
		}

	for (int j = 1; j < n - 1; j++)
		{
			int tmp = n - 1, i = j;;

			while (tmp >= 0 && i < n)
				{
					if (a[tmp][i] == -1)
						a[tmp][i] = nmb;

					tmp--;
					i++;
				}

			nmb = nmb % n + 1;
		}	

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << ' ';


			cout << endl;
		}	


	return 0;
}
