#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define F first
#define S second
#define MP make_pair

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	long long ans = n * 1ll * n;

	cout << ans << endl << n;
	
	return 0;
}
