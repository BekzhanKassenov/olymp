#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);

	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
	sort(a.begin(), a.end());

	int c = 1;

	int i = n - 2;
	while (a[i] == a[n - 1])
		{
			c++;
			i--;
		}
	cout << c;
	return 0;
}
