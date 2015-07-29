#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int a, b;
	
	cin >> a >> b;

	cout << b - 1 << ' ' << a - 1;

	return 0;
}
