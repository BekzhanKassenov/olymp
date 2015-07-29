#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <vector <int> > a(n, vector <int> (n));

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j] != a[j][i])
				{
					cout << "NO";
					return 0;
				}
   cout << "YES";
   return 0;
}
