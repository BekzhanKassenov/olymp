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

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int n;

    cin >> n;

    if (n == 1 || n == 2)
        {
            cout << -1;

            return 0;
        }

    cout << n << ' ' << n - 1 << ' ' << n - 2 << ' ';

    for (int i = n - 4; i >= 0; i--)
        cout << i + 1 << ' ';

    return 0;
}
