#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int c, ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	
			{
				cin >> c;
				ans+=c;
			}
	cout << ans;
	return 0;
}
