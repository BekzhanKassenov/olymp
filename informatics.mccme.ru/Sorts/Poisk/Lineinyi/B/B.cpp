#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int x;
	cin >> x;
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			{
				cout << "YES";
				return 0;
			}
	cout << "NO";
	return 0; 
}

