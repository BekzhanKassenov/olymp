#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector <string> a;

int n;

int c[10] = {0};

bool used[10] = {0};

bool operator < (const string& q, const string& b)
{
	int lena = (int)q.length();
	int lenb = (int)b.length();

	if (lena < lenb)
		return true;

	if (lena > lenb)
		return false;

	for (int i = 0; i < lena; i++)
		{
			if (c[q[i] - 'a'] < c[b[i] - 'a'])
				return true;

			if (c[q[i] - 'a'] > c[b[i] - 'a'])
				return false;
		}
	return false;
}

bool check()
{
	if (c[a[0][0] - 'a'] == 0)
		return false;
	for (int i = 1; i < n; i++)
		{
			if (c[a[i][0] - 'a'] == 0 || !(a[i - 1] < a[i]))
				return false;
		}

	return true;
}

void rec(int g)
{
	if (g == 10)
		{
			if (check())
				{
					cout << "YES" << endl;
					for (int i = 0; i < 10; i++)
						cout << c[i] << ' ';
					exit(0);
				}
			else
				return;
		}
	else
		{
			for (int i = 0; i < 10; i++)
				if (!used[i])
					{
						used[i] = true;
						c[g] = i;
						rec(g + 1);
						used[i] = false;
					}
		}
}

int main()
{
	freopen("tiv.in", "r", stdin);
	freopen("tiv.out", "w", stdout);

	cin >> n;

	a.resize(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	rec(0);

	cout << "NO";
	return 0;
}
