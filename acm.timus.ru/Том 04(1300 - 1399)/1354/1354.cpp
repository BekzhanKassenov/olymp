#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

bool check(const string &s)
{
	int l = 0, r = s.length() - 1;

	while (l < r)
		{
			if (s[l] != s[r])
				return false;

			l++, r--;
		}

	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	string s;

	cin >> s;


	for (int i = 1; i <= (int)s.length(); i++)
		{
			string tmp = s.substr(0, i);

		  	reverse(tmp.begin(), tmp.end());

		  	tmp = s + tmp;

		  	if (check(tmp))
		  		{
		  			cout << tmp << endl;
		  			return 0;
		  		}
		}	

	return 0;	
}
