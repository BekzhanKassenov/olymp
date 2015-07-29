#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long k = sqrt (n);
	int ans = 0;
	for (int i=1;i<=k;i++)
		{
			if (n%i==0)
				{
					if (i*i!=n)
						ans+=2;
					else
						ans++;
				}
		}
	cout << ans;
	return 0;
}
