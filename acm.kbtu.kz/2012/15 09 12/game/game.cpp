#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

#define MP make_pair
#define F first
#define S second

int len;

int str_to_int(string s)
{
	int ans = 0;
	for (int i = 0; i < len; i++)
		{
			ans *= 2;
			ans += ((s[i] == 'o') ? (1) : (0));
		}
	return ans;
}

string int_to_str(int n)
{
	string ans;
	while (n)
		{
			ans += (n % 2 == 1) ? ('o') : ('.');
			n /= 2;
		}
	if ((int)ans.length() < len)
		{
			for (int i = (int)ans.length(); i < len; i++)
				ans += '.';
		}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string s;
	cin >> s;
	len = (int)s.length();
	int nmb = str_to_int(s); 

	queue <int> q;
	
	q.push(nmb);
	
	vector < <pair<int, vector <int> > > > v;

	v.reserve(120000);

	vector <int> emt;

	int n = 0;
	
	while (!q.empty())
		{
			int it = q.front();
			string t = int_to_str(it);
			q.pop();
			v.push_back(make_pair(it, emt));
			n++;
			for (int i = 0; i < len; i++)
				{
					if (t[i] == 'o')
						{
							if (i < len - 1 && t[i + 1] != 'o')
								{
									string tmp = t;
									tmp[i] = '.';
									tmp[i + 1] = 'o';
									v[n - 1].S.push_back(str_to_int(tmp));
									q.push(str_to_int(tmp));
									cout << t << " -> " << tmp << endl;
								}
							if (i < len - 3 && t[i + 1] == 'o' && t[i + 2] == 'o' && t[i + 3] != 'o')
								{
									string tmp = t;
									tmp[i] = '.';
									tmp[i + 3] = 'o';
									v[n - 1].S.push_back(str_to_int(tmp));
									q.push(str_to_int(tmp));
									cout << t << " -> " << tmp << endl;
								}
						}
				}
		}
	sort(v.begin(), v.end());
	vector <bool> k(n);

	k[0] = 0;

	for (int i = 0; i < n; i++)
		{
			
		}
	return 0;
}

