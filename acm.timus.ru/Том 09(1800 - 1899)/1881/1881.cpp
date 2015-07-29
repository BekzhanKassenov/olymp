#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int h, w, n;

	cin >> h >> w >> n;

	int pos = 0;

	int ans = 1;

	string s;

     getline(cin , s);

	for (int i = 0; i < n; i++)
		{
		   getline(cin, s);

			int len = s.length();

			if (pos + len == w)
				{
					pos = 0;
					if (i != n - 1)
						ans++;
					//cout << s << endl;
					continue;
				}

			if (pos + len + 1 > w)
				{
					pos = len + 1;
					ans++;
					//cout << endl << s << ' ';
				}
			else
				{
					pos += len + 1;
					//cout << s << ' ';
				}
		}

	int t = ans / h;

	if (ans % h > 0)
		t++;

	//cout << endl << ' ' << ans << ' ' << h << ' ' << ans % h << endl;

	cout << t;

	return 0;	
}
