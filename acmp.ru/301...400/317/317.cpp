#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
	int x, y, z, n;
	cin >> x >> y >> z >> n;
	int i = 0, j = 0;
	int ans = 0;
	while (i * x <= n)
		{
			j = 0;
			while (n - i * x - j * y >= 0)
				{
					if ((n - i * x - j * y) % z == 0)
						ans ++;
					j++;
				}
			i++;
	  }
  cout << ans;
  return 0;
}
