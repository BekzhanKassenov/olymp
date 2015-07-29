#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string a[2];

int md(string &s)
{
	int ans = 0;

	ans = s[3] - '0';

	return (ans & 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> a[0] >> a[1];

	if (md(a[0]) == 0 || md(a[1]) == 1)
		cout << "yes";
	else
  		cout << "no";
  	return 0;
}
