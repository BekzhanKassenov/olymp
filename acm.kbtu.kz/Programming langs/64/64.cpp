#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	set <int> q;
	int m;
	cin >> m;
	int tmp;
	for (; m; m--)
		{
			cin >> tmp;
			q.insert(tmp);
		}
	for (int i = 0; i < n; i++)
		if (q.find(a[i]) == q.end())
			cout << a[i] << ' ';
	return 0;
}
