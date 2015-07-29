#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n, m;
	cin >> n >> m;
	int x, y;
	vector <int> stp(n);
	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			x--;
			y--;
			stp[x]++;
			stp[y]++;
		}
	for (int i = 1; i < n; i++)
		if (stp[i] != stp[i - 1])
			{
				cout << "NO";
				return 0;
			}
	cout << "YES";
	return 0;
}
