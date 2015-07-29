/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define sqr(x) (x) * (x)
#define INF (int) (2e9)
#define MOD (1000 * 1000 * 1000 + 7)
#define ull unsigned long long
#define ll long long

string er(string s)
{
    string ans;

    for (int i = 0; i < (int)s.length(); i++)
        {
            if (s[i] != ' ')
                ans += s[i];
        }

    return ans; 
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    vector <string> a;

    string s;

    while (getline(cin, s))
        {
            a.push_back(s);
        }

    int n = a.size();

    vector <bool> is(n);

    for (int i = 0; i < n; i++)
        {
            string tmp = er(a[i]);
            if (tmp[0] != '#')
                a[i] = tmp;
            else
                is[i] = true;
        }


    vector <bool> skl(n);

    for (int i = 1; i < n; i++)
        {
            if (is[i - 1] || is[i])
                skl[i] = false;
            else
                skl[i] = true;  
        }

    int i = 0;

    while (i < n)
        {
            cout << a[i];

            i++;

            while (i < n && skl[i])
                {
                    cout << a[i];
                    i++;
                }

            cout << endl;

        }

    return 0;
}