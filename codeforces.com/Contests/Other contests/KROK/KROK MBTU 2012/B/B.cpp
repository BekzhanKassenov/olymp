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
#define ll long long 
#define ull unsigned long long

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    string s;
    cin >> s;

    string ans;
    int pos;

    if (s.substr(3) == "ftp") {
        ans += "ftp://";
        pos = 3;
    } else {
        ans += "http://";
        pos = 4;
    }

    for (int i = s.length() - 2; i >= pos; i--) {
        if (s.substr(i, 2) == "ru") {
            ans += s.substr(pos, s.length() - (s.length() - i + pos)) + ".ru";
            pos = i + 2;
            break;
        }
    }

    if (pos < (int)s.length()) {
        ans += '/';
        
        for (int i = pos; i < (int)s.length(); i++)
            ans += s[i];
    }

    cout << ans << endl;
        
    return 0;              
}
