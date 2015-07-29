#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	while (n!= 1)
		{
			ans++;
			n = n / 2 + n % 2;
		}
	cout << ans;
	return 0;
}
