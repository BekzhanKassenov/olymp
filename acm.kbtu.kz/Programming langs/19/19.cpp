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

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] == a[j])
				{
					cout << i + 1 << ' ' << j + 1;
					return 0;
				}
	cout << "0 0";
	return 0;
}
