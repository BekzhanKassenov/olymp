#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n;i++)
		{
			cin >> a[i].first;
			a[i].second = i + 1;
		}

	sort(a.begin(), a.end());
	if (n > 1 && a[1].first == a[0].first)
		cout << "Still Rozdil";
	else
		cout << a[0].second;
		return 0;
}
