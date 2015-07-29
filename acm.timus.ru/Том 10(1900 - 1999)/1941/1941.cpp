#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector <int> to_vec(string s)
{
	vector <int> ans(s.length() / 4 + 1);

  	int pos = 0;

  	int len = ans.size();

  	for (int i = 0; i < len; i++)	
  		{
  			ans[i] = (s[pos] - 33) * 91 * 91 + (s[pos + 1] - 33) * 91 + s[pos + 2] - 33;
  			pos += 4;
  		}

  	return ans;	
}

int cnt, ans;

int couna[750000], counb[750000];

vector <int> a, b;

void inc(int ch, int z)
{
	if (couna[ch] == counb[ch])
		cnt--;

	counb[ch] += z;

	if (counb[ch] == couna[ch])
		cnt++;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	getline(cin, s);

	a = to_vec(s);

	getline(cin, s);

	b = to_vec(s);

	int lena = a.size(), lenb = b.size();

	for (int i = 0; i < lena; i++)
		{
			couna[a[i]]++;
		}

	if (lena > lenb)
		{
			cout << 0;
			return 0;
		}

	for (int i = 0; i < lena; i++)
		{
			inc(b[i], 1);
		}

	if (cnt == lena)
		ans++;

	for (int i = lena; i < lenb; i++)
		{
			inc(b[i - lena], -1);
			inc(b[i], 1);
			if (cnt == lena)
				ans++;
		}

	cout << ans;
	
	return 0;	
}
