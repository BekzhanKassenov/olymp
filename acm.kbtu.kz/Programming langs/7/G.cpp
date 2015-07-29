#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int m = 0;
	for (int i = 1; i <= n; i++)
		{
			int c = i;
			int ans = 0;
			while (c)
				{
					ans += c % 10;
					c /= 10;
				}	
			if (ans % k == 0)
				m++;
		}
   cout << m;
   return 0;
}
