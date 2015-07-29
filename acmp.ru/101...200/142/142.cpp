#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define F first
#define S second

using namespace std;

vector <int> t;

int get(int x)
{
    if (t[x] == x)
        return x;
    return t[x] = get(t[x]);
}

void un(int x, int y)
{
    int a = get(x);
    int b = get(y);
    t[a] = b;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    vector <pair <int, pair <int, int > > > g;
    g.resize(m);
    for (int i = 0; i < m; i++)
        {
            cin >> g[i].S.F >> g[i].S.S >> g[i].F;
            g[i].S.F --;
            g[i].S.S --;
        }
    sort(g.begin(), g.end());
    t.resize(n);
    for (int i = 0; i < n; i++)
        t[i] = i;
    int sc = 0;
    int ans = 0;
    for (int i = 0; i < m; i++)
        {
            if (sc == n - 1)
                break;
            int a = get(g[i].S.F);
            int b = get(g[i].S.S);
            if (a   != b)
                {
                    un(a,b);
                    ans += g[i].F;
                    sc++;
                }
        }
    cout << ans;
    return 0;
}
