#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	cin >> n;
	int ans = -1, mx = -1, f, c;
	for (int i = 1; i <= n; i++)
		{
			cin >> f >> c;
			if (c && (f > mx))
				{	
					mx = f;
					ans = i;
				}
		}
	cout << ans;
	return 0;
}

