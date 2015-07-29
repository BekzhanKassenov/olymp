/**************************************
***   Solution by Bekzhan Kassenov  ***
**************************************/
 
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
 
using namespace std;
 
#define sqr(x) (x) * (x)
#define abs(x) ((x) < 0)?(-(x)):(x)
#define PB push_back
#define PII pair <int, int>
#define MP make_pair
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define uld unsigned long double
#define INF (int)(2E + 9)
#define EPS 1E-14
#define min(x, y) (x < y) ? (x) : (y)
#define max(x, y) (x > y) ? (x) : (y)
 
int cnt = 0;
 
int log2(int n)
{
    int ans = 0;
    int c = n;
    while (n)
        {
            ans ++;
            n >>= 1;
        }
 
    ans--;
 
    if (c == (1 << ans))
        ans--;
 
    //cout << c << ' ' << ans << endl;
 
    return ans;
}
 
void solve(int n)
{
    if (n == 1 || n == 0)
        return;
 
    //cout << n << endl;    
 
    int q = log2(n);
 
    solve(n - (1 << q));
    cnt++;
}
 
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
 
    cin >> n;
 
    solve(n);
 
    cout << cnt % 3;
 
    return 0;
}