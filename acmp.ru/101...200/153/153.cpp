#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector <int> b;

int n, m;

struct triple
{
	int a[16];

	int sz;
	
	triple()
		{
			sz = 0;
		}

	triple(int n)
		{
			sz = 0;
			
			for (int i = 0; i < 16; i++)
				a[i] = 0;

			if (n == 0)
				{
					a[sz++] = 0;
					return;
				}

			while (n)
				{
					a[sz++] = n % 3;
					n /= 3;
				}
		}

	void inc()
		{
			a[0]++;

			int pos = 0;

			while (pos < sz && a[pos] == 3)
				{
					a[pos++] = 0;
					a[pos] ++;
				}


			if (a[sz] != 0)
				sz++;
		}

  	void print()
  		{
  			for (int i = sz - 1; i >= 0; i--)
  				cout << a[i];

  			cout << endl;
  		}

	bool operator < (const triple &t)
		{
			if (sz < t.sz)
				return true;

			if (sz > t.sz)
				return false;

			for (int i = sz - 1; i >= 0; i--)
				{
					if (a[i] < t.a[i])
						return true;

					if (a[i] > t.a[i])
						return false;
				}

			return false;
		}

	void get(int &sum, int &cnt)
		{
			for (int i = 0; i < sz; i++)
				{
					sum += b[i] * a[i];
					
					if (sum > n)
						{
							sum = n + 1;
							return;
						}

					cnt += a[i];
				}
		}
}; 

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d%d", &n, &m);

	b.resize(m);

	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);

	int tre = 3;

	for (int i = 1; i < m; i++)
		tre *= 3;

	bool flag1 = false;

	int ans = 10000;

	int sum;

	int cnt;

	triple mask = triple(0);

	for (int i = 0; i < tre; i++)
		{
			sum = 0; 
			cnt = 0;

			mask.get(sum, cnt);
			
			if (sum == n)
				ans = min(ans, cnt);

			if (sum >= n)
				flag1 = true;

			mask.inc();
		}

	if (flag1)
		{
			if (ans != 10000)
				printf("%d", ans);
			else
				puts("0");
		}	
	else
		puts("-1");

	return 0;
}
