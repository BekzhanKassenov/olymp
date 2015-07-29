#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

 	for (int i = 0; i < n; i++)
 		{
 			for (int j = 0; j < m; j++)
 				{
 					if (a[i][j] == 1)
 						cout << 0 << ' ';
 					else
 						{
 							int ans = 100000;
 							for (int x = 0; x < n; x++)
 								for (int y = 0; y < m; y++)
 									if (a[x][y] == 1)
 										ans = min(ans, (int)(abs(x - i) + abs(y - j)));
 							cout << ans << ' ';
 						}
 				}
 			cout << endl;
 		}
	return 0;
}
