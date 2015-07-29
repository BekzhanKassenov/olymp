#include <iostream>
#include <vector>

using namespace std;

int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, -1, 0, 1};

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
   int x = 0;
   int y = 0;
   ans += a[0][0];
   a[0][0] = 0;
   for (int i = 0; i < k - 1; i++)
   	{
   		int z;
   		cin >> z;
   		x += nx[z - 1];
   		y += ny[z - 1];
   		ans += a[y][x];
   		a[y][x] = 0;
   	}
   cout << ans << endl;
}

