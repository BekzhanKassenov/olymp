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

    vector <int> d(n);

    int sum = 0;

    for (int i = 0; i < n; i++)
        {
            cin >> d[i];
            sum += d[i];
        }

    int s, t;

    cin >> s >> t;

    s--, t--;

    if (s > t)
        swap(s, t);

    int ans = 0;

    for (int i = s; i < t; i++)
        {
            ans += d[i];
        }

    cout << min(ans, sum - ans);


    return 0;
}
