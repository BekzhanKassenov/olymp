#include <iostream>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;
const int base = 107;

string get_next(string &s, int &pos)
{
	string ans;

	while (pos < (int)s.length() && s[pos] != 0 && s[pos] != 13 && s[pos] != 10 && s[pos] != ' ')
		ans += s[pos++];

	return ans;
}
	
int hash_function(const string &s)
{
	long long hash = 0;

	for (int i = 0; i < (int)s.length(); i++)
		{
			hash *= base;
			hash += s[i];
			hash %= MOD;
			if (hash < 0)
				hash += MOD;
		}

	return  (int)hash;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	string s;

	getline(cin , s);

	set <int> mats;

	for (int i = 0; i < n; i++)
		{
		   getline(cin, s);

		   cout << s << endl;

			mats.insert(hash_function(s));
		}

	cin >> n;

	for (int i = 0; i < n; i++)
		{
			getline(cin, s);

			int pos = 0;

			while (pos < (int)s.length())
				{
					int ps = pos;

					string tmp = get_next(s, ps);

					cout << tmp << endl;

					int h = hash_function(tmp);

					if (mats.find(h) != mats.end())
						{
							cout << i + 1 << ' ' << pos + 1;
							return 0;
						}

					else
						pos = ++ps;
			   }
		}
	cout << "Passed" << endl;
}
