#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector <vector <int> > dp;

vector <vector <string> > pr;

string s;

string int_to_str(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}

bool check(int l, int r, int k)
{
    int n = r - l + 1;

    if (k == n)
        {
            for (int i = l + 1; i <= r; i++)
                if (s[i] != s[i - 1])
                    return false;
            return true;
        }
    k = n / k;

    for (int j = l + k; j <= r; j++)
        {
            if (s[j] != s[j - k])
                {
                    return false;
                }
        }
    return true;

}

void make(int l, int r, int i);

void calc(int l, int r)
{
    int n = r - l + 1;
    //cout << l << ' ' << r << endl;

    if (dp[l][r] != -1)
        return;

    if (check(l, r, n))
        {
            string k = int_to_str(n);
            dp[l][r] = (int)k.size() + 2 + 1;
            pr[l][r] = k + '(' + s[l] + ')';
        }
    for (int i = 2; i * i <= n; i++)
        {
            if (n % i != 0)
                continue;

            if (check(l, r, i))
                make(l, r, i);
            
            if (i * i == n) 
                continue;

            if (check(l, r, n / i))
                make(l, r, n / i);

        }
    for (int k = l; k < r; k++)
        {
            if (dp[l][k] == -1) 
                calc(l, k);
            if (dp[k + 1][r] == -1)
                calc(k + 1, r);

            if (dp[l][r] > dp[l][k] + dp[k + 1][r] || dp[l][r] == -1)
                {
                    dp[l][r] = dp[l][k] + dp[k + 1][r];
                    pr[l][r] = pr[l][k] + pr[k + 1][r];
                }
        }
}

void make(int l, int r, int i)
{   
    int n = r - l + 1;  

    if (dp[l][l + n / i - 1] == -1)
        calc(l, l + n / i - 1);
    
    string ans = int_to_str(i) + '(' + pr[l][l + (n / i) - 1] + ')';
    
    if ((dp[l][r] > (int)ans.length()) || dp[l][r] == -1)
        {
            dp[l][r] = (int)ans.length();
            pr[l][r] = ans;
        }

}


int main()
{
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);
    
    cin >> s;
    int n = s.length();

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

    cout << pr[0][n - 1] << endl;

    return 0;
}

