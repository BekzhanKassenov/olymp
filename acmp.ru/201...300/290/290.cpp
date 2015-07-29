#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int na, ma;

	cin >> na >> ma;

	vector <vector <int> > a(na, vector <int> (ma));

	char c;

	for (int i = 0; i < na; i++)
		{
			for (int j = 0; j < ma; j++)
				{
					cin >> c;
					if (c == '#')
						a[i][j] = 1;
					else
						a[i][j] = 0;
				}
		}

	int nb, mb;

	cin >> nb >> mb;

	vector <vector <int> > b(nb, vector <int> (mb));

	for (int i = 0; i < nb; i++)
		for (int j = 0; j < mb; j++)
			{
				cin >> c;

				if (c == '#')
					b[i][j] = 1;
				else
					b[i][j] = 0;
			}

	int ans = 0;

  	for (int i = 0; i <= nb - na; i++)
  		{
  			for (int j = 0; j <= mb - ma; j++)
  				{
  					bool flag = true;

  					for (int k = 0; k < na && flag; k++)
  						{
  							for (int z = 0; z < ma && flag; z++)
  								{
  									if (b[i + k][j + z] == a[k][z] || (a[k][z] == 0 && b[i + k][j + z] == 1))
  										continue;
  									
  									flag = false;
  								}
  						}

  					if (flag)
  						ans++;
  				}
  		}

  	cout << ans;

  	return 0;
}
