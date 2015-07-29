#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	
	cin >> n;
	
	long long ans = 1;
	
	while (n != 3 && n != 2 && n != 4 && n != 1)
		{
			n -= 3;
			ans *= 3;
		}
	
	ans *= n;
	
	cout << ans;

	return 0;
}
