#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	
	cin >> n;
	
	vector <int> a(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	vector <int> b = a;
	
	int m;
	
	cin >> m;

	int x, y;
	
	for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			for (int j = 0; j < n; j++)
				if (a[j] == x)
					b[j] = y;
		}

	for (int i = 0; i < n; i++)
		cout << b[i] << ' ';

	cout << endl;

	return 0;	
}
