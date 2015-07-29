#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

#define int long long

int str_to_int(string s)
{
	int ans = 0;
	for (int i = 0; i < (int)s.length(); i++)
		ans = ans * 10 + s[i] - '0';

	return ans;
}

string int_to_str(int n)
{
	string s;

	while (n)
		{
	   	s += (n % 10) + '0';
	   	n /= 10;
		}	

	reverse(s.begin(), s.end());
	return s;
}

main()
{
	freopen("out", "w", stdout);
	int n;

	cin >> n;

	int ten = 10;

	for (int i = 1; i < n; i++)
		ten *= 10;

	int ans = 0;

	int s = ten / 10;

	for (int i = s; i < ten; i++)
		{
			int j = 1;

			int q = i * s;

			while (1)
				{
					if (i * j < ten)
						{
							if ((q + i * j) % (i * j) == 0)
								{
									ans++;
							//		cout << i << i * j << endl;
								}
						}
					else
						break;
					j++;
				}
      }
   cout << ans;
}

