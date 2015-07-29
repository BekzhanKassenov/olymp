#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define VI vector <int>

int a[32], b[32];

int sizea, sizeb;

inline void dec_to(int x, int to, int* ans, int &sz)
{
   sz = 0;
	while (x)
		{
			ans[sz++] = x % to;
			x /= to;
		}

}

inline bool get_next(int &pos, int len, int n)
{
	if (pos >= len)
		return false;

	while (a[pos] != n && pos < len)
		pos++;

	if (pos < len && a[pos] == n)
		{
		 	pos++;
		 	return true;
		}
	else
		{
			pos++;
			return false;
		}
}

inline bool check()
{
	int pos = 0;

	for (int i = 0; i < sizeb; i++)
		{
			if (!get_next(pos, sizea, b[i]))
				return false;
		}

	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	int x, y;

	cin >> x >> y;

	for (int i = 2; i <= max(x, y) + 1; i++)
		{
			dec_to(x, i, a, sizea);
			dec_to(y, i, b, sizeb);

			if (check())
				{
					cout << i;
					return 0;
				}
		}

	cout << "No solution";
	return 0;
}
