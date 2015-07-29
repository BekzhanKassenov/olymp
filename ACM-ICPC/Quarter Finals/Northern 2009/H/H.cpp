#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	freopen("homo.in", "r", stdin);
	freopen("homo.out", "w", stdout);

	int n;

	ios_base :: sync_with_stdio(false);

	cin >> n;

	string s;

	map <int, int> m;

	int cnt = 0;

	for (int i = 0; i < n; i++)
		{
			cin >> s;

			int n;

			cin >> n;

			if (s == "insert")
				{
					m[n]++;

					if (m[n] == 2)
						cnt++;
				}
			else
				{
					if (m.find(n) != m.end())
						{
							m[n]--;
							if (m[n] == 0)
								m.erase(n);
							else
								if (m[n] == 1)
									cnt--;
						}
				}	

			bool homo = cnt;
			bool hetero = m.size() > 1;

			if (homo && hetero)
				cout << "both";
			else
				if (homo && !hetero)
					cout << "homo";
				else
					if (!homo && hetero)
						cout << "hetero";
					else
						cout << "neither";

			cout << endl;	
		}
}
