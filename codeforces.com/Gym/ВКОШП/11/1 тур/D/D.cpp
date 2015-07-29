#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

vector <int> prime;

void build(int n)
{
	vector <bool> tmp;

	tmp.assign(n + 1, 1);

	tmp[0] = tmp[1] = 0;

	for (int i = 2; i <= n; i++)
		{
			if (tmp[i])
				{
					prime.push_back(i);
					if (i * ((long long)(1)) * i <= n)
						for (int j = i * i; j <= n; j += i)
							tmp[j] = false;
				}

		}

}

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	int n;

	cin >> n;

	vector <int> a(n);

	int mx = 0;

	for (int i = 0; i < n; i++)
		cin >> a[i];        

	sort(a.begin(), a.end());

	mx = a[n - 1];

	build(mx);

	vector <bool> win(n, true);

	vector <int> ans;

	for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < prime.size(); k++)	
				{
					vector <int> now;
					for (int j = 0; j < n; j++)
						{
							if (a[j] % prime[k] == a[i] % prime[k])
								now.push_back(j);
						}

					bool w = now.size() % 2;

					if (now.size() == 1)
						continue;

		//			cout << endl;

		//			cout << prime[k] << endl;

					for (int j = 0; j < now.size(); j++)
						{
		//					cout << a[now[j]] << ' ';
							if (w == 0)
								win[now[j]] = 0;
						}
		//			cout << endl;
				}
		 }

  	for (int i = 0; i < n; i++)
  		{	
  			if (win[i])
  				ans.push_back(a[i]);
  		}

  	cout << ans.size() << endl;

  	for (int i = 0; i < ans.size(); i++)
  		cout << ans[i] << ' ';

	return 0;

}