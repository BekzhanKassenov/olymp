#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b;

	cin >> a >> b;

	if (a % 2 == 0)
		a++;


	int ans = 0;

	for (int i = a; i <= b; i += 2)
		ans++;

	cout << ans;

	return 0;
}
