#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE 
		freopen("in", "r", stdin);
	#endif

	int n, k;

	cin >> n >> k;

	if (k > n)
		cout << 0;
	else
		cout << (n * (n / k) + (n % k) * (n / k));

	return 0;	
}
