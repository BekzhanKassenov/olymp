#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

#define abs (x) (x < 0)?(-x):(x)
#define sqr(q) (q)*(q)
#define inf 1000000000
#define ll long long 

int main()
{
    
    ll n, d, a, b;
    cin >> n >> d;
    cin >> a >> b;
    vector <pair <ll, ll> > cl(n);
    ll x,y;
    for (ll i = 0; i < n; i++)
        {   
            cin >> x >> y;
            cl[i].first = a * x + b * y;
            cl[i].second = i + 1;
        }
    sort(cl.begin(), cl.end());
    ll k = 0;
    vector <ll> ans;
    ll i = 0;
    while (k < d && i < n)
        {
            k += cl[i].first;
            i ++;
        }
    if (k > d)
    i--;
    cout << i << endl;
    for (int j = 0; j < i ; j ++)
        cout << cl[j].second << ' ';
    return 0;
}