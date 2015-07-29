#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <pair <int, int> > a(n);

	for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			a[i].second = i + 1;
		}
	sort(a.rbegin(), a.rend());

	for (int i = 0; i < n; i++)
		cout << a[i].second << ' ';
	return 0;
}
