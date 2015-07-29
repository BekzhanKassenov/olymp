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

void pp(string& s)
{
    int len = s.size();

    for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] < 'z')
                {
                    s[i]++;
                    return;
                }
        }

    for (int i = 0; i < len; i++)
        s[i] = 'a';

    s += 'a';

    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int n;

    cin >> n;

    string t;

    set <string> s1, s2;

    while (n--) 
        {
            cin >> t;                        

            int len = t.size();

            for (int i = 0; i < len; i++)
                s1.insert(t.substr(i, 1));

            for (int i = 0; i < len - 1; i++)
                s2.insert(t.substr(i, 2));
        }

    for (char i = 'a'; i <= 'z'; i++)
        {
            string s;

            s += i;

            if (s1.find(s) == s1.end())
                {
                    cout << s << endl;
                    return 0;
                }
        }

    for (char i = 'a'; i <= 'z'; i++)
        {
            for (char j = 'a'; j <= 'z'; j++)
                {
                    string tmp;
                    tmp += i;
                    tmp += j;

                    if (s2.find(tmp) == s2.end())
                        {
                            cout << tmp;
                            return 0;
                        }
                }
        }


    return 0;
}
