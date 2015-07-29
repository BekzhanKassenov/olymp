#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define PII pair <int, int>
#define MP make_pair
#define F first
#define S second
#define INF 2000000000

vector <int> cbs;

vector <vector <int> > dp;

int cnt;

bool flag = false;

bool rec(int n, int m, int gl)
{
	if (gl > 8)
		return INF;
	if (n == 0)
		{
			cout << m + 1 << ' ';
			flag = true;
			return true;
		}	
	for (int i = m; i >= 0; i--)
		if (n - cbs[i] >= 0)
			{
				bool k = rec(n - cbs[i], i, gl + 1);
				//if (!k) break;

				if (flag)
					{
						if (gl != 0)
							cout << m + 1 << ' ';
						return true;
					}
			}
	return false;
}

 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
   
   for (int i = 1; i * i * i <= n; i++)
		cbs.push_back(i * i * i);

	cnt = (int)cbs.size();

	if (!rec(n, cnt - 1, 0))
		cout << "IMPOSSIBLE";
	return 0;
}
