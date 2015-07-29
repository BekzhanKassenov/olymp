#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <pair <int, int> > a;

	for (int i = 0; i < n; i++)
		{
			int tmp;

			cin >> tmp;

			if (a.empty() || a.back().first != tmp)
				{
					a.push_back(make_pair(tmp, 1));
				}

			else
				a.back().second++;
		}

	for (int i = 0; i < (int) a.size(); i++)
		{
			cout << a[i].second << ' ' << a[i].first << ' ';
		}
}
