#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int x;
	cin >> x;
	int n;
	cin >> n;
	vector <vector <int> > a(n, vector <int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
		{
			bool flag = false;
			for (int j = 0; j < n; j++)
				{
					if (a[j][i] == x)
						{
							cout << "YES" << endl;
							flag = true;
							break;
						}
		   	}
		   if (!flag)
				cout << "NO" << endl;
	   }
   return 0;
}
