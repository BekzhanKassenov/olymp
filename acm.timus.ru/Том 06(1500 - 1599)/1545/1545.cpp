#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <string> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	char c;

	cin.get(c);

	cin.get(c);

	for (int i = 0; i < n; i++)
		if (a[i][0] == c)
			cout << a[i] << endl;

	return 0;

}
