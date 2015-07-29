#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	vector <int> a(1001);

	long long n;

	cin >> n;

	for (int i = 2; i <= 1000; i++)
		{
			while (n % i == 0)
				{
					n /= i;
					a[i]++;
				}
		}

	long long ans = 1;

	for (int i = 1; i <= 1000; i++)
		{
			ans *= (a[i] + 1);
		}
	cout << ans;
	return 0;
}

