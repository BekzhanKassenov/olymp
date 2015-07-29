#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector <vector <int> > a(n, vector <int> (n));
	vector <int> b(n,0);

	int ans = 0;
	
	for (int i = 0; i < n;i++)
		{
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		}
	
	for (int i = 0; i < n; i++)
		cin >> b[i];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((a[i][j] == 1) && (b[i] != b[j])) ans++;
	cout << ans/2;
	return 0;
}
