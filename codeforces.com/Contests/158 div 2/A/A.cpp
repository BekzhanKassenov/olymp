/********************************************
***     Solution by Bekzhan Kassenov      ***
********************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define sqr(x) (x) * (x)
#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define VI vector <int>
#define VII vector <VI>
#define ll long long
#define ull unsigned long long
#define INF
#define MOD
#define EPS

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int a, b, n;

    cin >> a >> b >> n;

    stringstream ss;

    ss << a;

    a %= b;

    for (int i = 0; i < n; i++)
        {
            a *= 10;

            a %= b;

            bool flag = false;

            for (int j = 0; j < 10; j++)
                {
                    if ((a + j) % b == 0)
                        {
                            ss << j;
                            a += j;
                            flag = true;
                            break;
                        }
                }

            if (!flag)
                {
                    cout << -1;
                    return 0;
                }
        }

    string ans;

    ss >> ans;

    cout << ans;

    return 0;
}