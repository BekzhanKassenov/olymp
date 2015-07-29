#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string int_to_str(int a)
{
	string ans;
	while (a)
		{
			ans += a % 10;
			a /= 10;
		}
	return ans;
}

int str_to_int (string s)
{
	int ans;
	for (int i = 0; i < s.length(); i++)
		{
			ans *= 10;
			ans += s[i];
		}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	string stra = int_to_str(a);
	string strb = int_to_str(b);
	sort(stra.begin(), stra.end());
	sort(strb.begin(), strb.end());
	do
		{
			int k = str_to_int(stra);
			int v = c - k;
			string str = int_to_str(v);
			sort(str.begin(), str.end());
			if (str == strb)
				{
					cout << "YES" << endl << k << ' ' << v;
					return 0;
				}
		}
	while (next_permutation(stra.begin(), stra.end()));
	cout << "NO";
	return 0;
}
