#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;

	cin >> s;

	sort(s.begin(), s.end());

	do
		{
			cout << s << endl;
		}

	while (next_permutation(s.begin(), s.end()));

	return 0;
}
