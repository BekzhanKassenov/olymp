#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	multiset <int> t;

	long long ans = 0;

	string s;

	int sz = 0;

	while (cin >> s)
		{
			if (s == "QUIT")
				break;

			double d;

			cin >> d;

			int x = (int) (d * 100 + 0.01);

			if (s == "BID")
				{
					t.insert(x);
					sz++;
				}

			if (s == "DEL")
				{
					t.erase(x);
					sz--;
				}

			if (s == "SALE")
				{
					int c;

					cin >> c;

					int cnt = 0;

					for (multiset <int> :: iterator it = t.begin(); it != t.end(); it++)
						{
							if (*it >= x)
								break;

							cnt++;
						}

					ans += max(0, min(sz - cnt, c));
				}
		}

	printf("%.2lf", (double(ans)) * 0.01);
	return 0;
}
