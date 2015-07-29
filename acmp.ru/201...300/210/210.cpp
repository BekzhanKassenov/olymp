#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;

	map <int, int> m;

	int k = (int)sqrt(double(n));

	for (int i = 2; i <= k; i++)
		{
			while (n % i == 0)
				{
					m[i]++;
					n /= i;
				}
		}

	if (n != 1)
	   m[n]++;

	int q = 1;

	for (map <int, int> :: iterator it = m.begin(); it != m.end(); it++)
		q *= it -> F;

	for (int j = 1; ; j++)
		{
			int tmp = q * j;

			bool flag = true;

			int k = (int)sqrt(double(tmp));

			for (int i = 2; i <= k; i++)
				{
					if (tmp % i == 0 && tmp != 1)
						{
							int cnt = 0;

							while (tmp % i == 0)
								{
									cnt++;
									tmp /= i;
								}

							if (cnt * q * j < m[i])
								{
									flag = false;
									break;
								}
						}
				} 

			if (tmp != 1)
				if (q * j < m[tmp])
					flag = false;

		  	if (flag)
		  		{
		  			cout << q * j;
		  			return 0;
		  		}
		}

	return 0;	
}
