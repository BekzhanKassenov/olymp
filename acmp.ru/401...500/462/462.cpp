#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;

	
	cin >> n;
	
	int ans = n - n / 2 - n / 3 - n / 5 + n / 6 + n / 10 + n / 15 - n / 30;
	
	cout << ans;
}
