#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int mx = 0, mn = 10;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] > mx)
				mx = a[i];
			if (a[i] < mn)
				mn = a[i];
		}
	for (int i = 0; i < n; i++)
		if (a[i] == mx)
			cout << mn << ' ';
		else
			cout << a[i] << ' ';
	return 0;	
}
