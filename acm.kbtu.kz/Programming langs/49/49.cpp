#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector <vector <int> > a(n, vector <int> (m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
   int k;
   cin >> k;
   int ans = 0;
   for (int i = 0; i < k; i++)
   	{
   		int x, y;
   		cin >> x >> y;
   		
   		ans += a[--x][--y];
   		a[x][y] = 0;
   	}
   cout << ans << endl;
}
