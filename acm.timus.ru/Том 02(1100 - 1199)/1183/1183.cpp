#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>

using namespace std;

char para(char k)
{
	switch (k)
		{
			case '(': 
				return ')';
			case ')':
				return '(';
			case '[':
				return ']';
			case ']':
				return '[';
		}
}

string s;

int len;

vector <vector <int> > dp;

vector <vector <string> > pr;

bool check(int l, int r)
{
	stack <char> st;

	for (int i = l; i <= r; i++)
		{
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else
				{	
					if (st.empty())
						return false;

					if (st.top() != para(s[i]))
						return false;

					st.pop();
				}

		}
	if (st.empty())
		return true;

	return false;	
}

string get(char c)
{
	string ans;

	if (c == '(' || c == '[')
		{
			ans += c;
			ans += para(c);
		}
	else
		{
			ans += para(c);
			ans += c;
		}	

	return ans;
}

void rec(int l, int r)
{
	if (dp[l][r] != -1)
		return;

	if (l > r)
		{
			dp[l][r] = 0;
			return;
		}

	if (l == r)
		{
			dp[l][r] = 1;

			pr[l][r] = get(s[l]);
			return;
		}

	if (r - l == 1)
		{
			if (s[l] == '(' && s[r] == ')' || s[l] == '[' && s[r] == ']')
				{
					dp[l][r] = 0;
					pr[l][r] += s[l];
					pr[l][r] += s[r];
				}
			else
				{
					dp[l][r] = 2;
					pr[l][r] += get(s[l]);
					pr[l][r] += get(s[r]);
				}

			return;	
		}

	if (s[l] == ')' || s[l] == ']')
		{
			rec(l + 1, r);
			dp[l][r] = dp[l + 1][r] + 1;

			pr[l][r] = get(s[l]) + pr[l + 1][r];
			return;
		}

	if (s[r] == '(' || s[r] == '[')
		{
			rec(l, r - 1);

			dp[l][r] = dp[l][r - 1] + 1;

			pr[l][r] = pr[l][r - 1] + get(s[r]);
			return;
		}

	string ans_str;
	int ans_int = 100000;

	if (s[l] == para(s[r]))
		{
			rec(l + 1, r - 1);

			ans_int = dp[l + 1][r - 1];
			
			ans_str += s[l];
			ans_str += pr[l + 1][r - 1];
			ans_str += s[r];
		}

	for (int i = l; i < r; i++)
		{
			rec(l, i);
			rec(i + 1, r);

			if (dp[l][i] + dp[i + 1][r] < ans_int)
				{
					ans_str = pr[l][i] + pr[i + 1][r];
					ans_int = dp[l][i] + dp[i + 1][r];
				}
		}

	//cout << l << ' ' << r << ' ' << ans_str << endl;

  	dp[l][r] = ans_int;
  	pr[l][r] = ans_str;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif

	cin >> s;

	if (s.empty())
		{
			cout << endl;
			return 0;	
		}

	len = s.length();

	dp.resize(len, vector <int> (len, -1));

	pr.resize(len, vector <string> (len));

	rec(0, len - 1);

	cout << pr[0][len - 1];

	return 0;
}
