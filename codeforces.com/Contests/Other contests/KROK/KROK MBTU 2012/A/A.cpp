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

int a[2][2], n, tmp, x, y;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmp >> x >> y;
        a[tmp][0] += x;
        a[tmp][1] += y;
    }
   
    if (a[0][0] >= a[0][1])
        cout << "LIVE" << endl;
    else
        cout << "DEAD" << endl;

    if (a[1][0] >= a[1][1])
        cout << "LIVE" << endl;
    else
        cout << "DEAD" << endl;

    return 0;
}
