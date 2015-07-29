#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	map <string, int> m;

	for (int i = 0; i < n; i++)
		{
			string s;

			cin >> s;

			m[s]++;
		}

	for (map <string, int> :: iterator it = m.begin(); it != m.end(); it++)
		{
			if (it -> second > 1)
				{
					cout << it -> first << endl;
				}
		}

	return 0;
}
