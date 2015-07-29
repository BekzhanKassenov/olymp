#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int n;

	cin >> n;

	vector <int> primes;

	vector <bool> prime(170000, 1);

	for (int i = 2; primes.size() != 15001; i++)	
		{
			if (prime[i])
				{
					if (i * 1ll * i < 170000)
						for (int j = i * 1ll * i; j < 170000; j += i)
							prime[j] = false;
					primes.push_back(i);
				}

		}


	int tmp;

	for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			cout << primes[tmp - 1] << endl;
		}

	return 0;

}
