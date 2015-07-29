#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector <vector <int> > dp;

vector <vector <string> > pr;

int n;

string s;

inline string int_to_str(int s)
{
	stringstream ss;

	ss << s;

	return ss.str();
}

bool check(int l, int r, int cnt)
{
	int len = (r - l + 1);

	/*if (cnt == 1)
		{
			for (int i = l + 1; i <= r; i++)
				if (s[i] != s[i - 1])
					return false;

			return true;
		}*/	

	for (int i = l; i + cnt <= r; i++)
		if (s[i] != s[i + cnt])
			return false;

	return true;
}

int calc(int l, int r)
{
	if (dp[l][r] != -1)
		return dp[l][r];

	int len = r - l + 1;

	dp[l][r] = len;
	pr[l][r] = s.substr(l, len);

	//cout << l << ' ' << r << ' ' << len << endl;

	for (int i = 1; i * i <= len; i++)
		{
			if (len % i == 0)
				{
					if (check(l, r, i))
						{
							string tmp = int_to_str(len / i);
							
							int q = calc(l, l + i - 1) + 2 + (int)tmp.length();

							if (q < dp[l][r])
								{
									dp[l][r] = q;
									pr[l][r] = tmp + '(' + pr[l][l + i - 1] + ')';
								}
						}

					if (check(l, r, len / i))
						{
							string tmp = int_to_str(i);

							int q = calc(l, l + len / i - 1) + 2 + (int)tmp.length();

							if (q < dp[l][r])
								{
									dp[l][r] = q;
									pr[l][r] = tmp + '(' + pr[l][l + len / i - 1] + ')';
								}
						}	
				}
		}

  	for (int k = l; k < r; k++)
  		{
  			int a = calc(l, k);
  			int b = calc(k + 1, r);

  			if (a + b < dp[l][r])
  				{
  					dp[l][r] = a + b;
  					pr[l][r] = pr[l][k] + pr[k + 1][r];
  				}
  		}

  	return dp[l][r];

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> s;

	n = (int) s.length();

	dp.assign(n, vector <int> (n, -1));

	pr.assign(n, vector <string> (n));

	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
				{
					if (i + j < n)
					{
						dp[i][i + j] = j + 1;
						pr[i][i + j] = s.substr(i, j + 1);
					}
				}
		}


	calc(0, n - 1);
	
	cout << pr[0][n - 1];

	return 0;
}
