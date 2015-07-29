#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int len; // dlina stroki

string get_by_mask(int n) //funkciya dlya polucheniya stroki po maske
{
	string ans;
	for (int i = 0; i < len; i++)
		if ((n & (1 << i)) > 0)
			ans += s[i];
	return ans;
}

int main()
{
	cin >> s;
	len = s.length();
	int ans = 0;
	for (int i = 0; i < (1 << len); i++)
		{
			string str = get_by_mask(i);
			sort(str.begin(), str.end());
			do
				{
					cout << str << endl;
					ans++;
				}
			while (next_permutation(str.begin(), str.end()));
		}
	cout << ans << endl;
	return 0;

}
