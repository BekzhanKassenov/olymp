#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	int s, m;

	cin >> s >> m;

	int tmp = s;

	int i = 0;

	while (tmp > 0)
		{
		   if (tmp >= 9)
		   	{
		   		cout << '9';
		   		tmp -= 9;
		   	}

		   else
		   	{
		   		cout << char(tmp + '0');
		  			tmp = 0;
		  		}	

			i++;
		}

	while (i < m)
		{
			cout << 0;
			i++;
		}

	cout << endl;

	vector <int> a(m);

	a[0] = 1;

	s--;

	for (i = m - 1; i >= 0; i--)
		{
			if (s >= 9)
				{
					a[i] += 9;
					s -= 9;
				}
			else
				{
					a[i] += s;
					s = 0;
					break;
				}
		}

	for (int i = 0; i < m; i++)
		cout << a[i];

	cout << endl;

	return 0;

}
