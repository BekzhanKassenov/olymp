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

	string :: iterator it = s.begin();

	while (*it == '0')
		it++;

	iter_swap(it, s.begin());

	cout << s << ' ';

	sort(s.rbegin(), s.rend());
		
	cout << s << endl;

	return 0;
}
