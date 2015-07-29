#include <iostream>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

void calc_c()
{
	c[0][0] = 1;
	for (int i = 1; i < MAX_LOG; i++)
		{
			c[i][0] = c[i][i] = 1;

			for (int j = 1; j < i; j++)
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
}

int get_dyn(int n)
{
	int tmp = n;

	int cnt = 0;

	int len = 0;

	while (tmp)
		{
			cnt += (tmp & 1);
			tmp >>= 1;
			len++;
		}

	int ans = 0;

	for (int i = len - 1; i >= 0; i--)
		{
			if (!(n & (1 << i)))
				continue;

			else
				ans += c[len - i][cnt--];
		}

	return ans;
}

int get_slow(int n)
{
	int tmp = n;

	int cnt = 0;

	while (tmp)
		{
			cnt += (tmp & 1);
			tmp >>= 1;
		}

	for (int i = 0; i < 
}

int main()
{
	int n;

	cin >> n;

	int a = get_dyn(n);

	int b = get_slow(n);

	if (a == b)
		cout << "OK";

	return 0;
}
