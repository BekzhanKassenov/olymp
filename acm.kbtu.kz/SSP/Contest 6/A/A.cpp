#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector <vector <int> > d(n + 1, vector <int> (n + 1,0));
    d[1][1] = 1;
    for (int i = 1; i <= n; i++)    
        {
            for (int j = 1; j <= n; j++)
                {
                    if (s[i-1] == '(')
                        d[i][j] = d[i - 1][j - 1];
                    if (s[i-1] = ')')
                        d[i][j] = d[i - 1][j + 1];
                    if (s[i-1] == '?')
                        d[i][j] = (d[i - 1][j + 1] + d[i - 1][j - 1]) % 301907;
                }
        }   
    cout << d[n][1];
    return 0;
}
