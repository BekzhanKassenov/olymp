#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second
#define MP make_pair
#define sqr(x) (x) * (x)
#define INF (int)2e9

vector <PII> g;

set <PII> s;

inline int dist(int a, int b)
{
    if (s.find(MP(a, b)) != s.end() || s.find(MP(b, a)) != s.end())
        return 0;

    return (sqr(g[a].F - g[b].F) + sqr(g[a].S - g[b].S));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    g.resize(n);

    for (int i = 0; i < n; i++)
        cin >> g[i].F >> g[i].S;

    int m;

    cin >> m;

    int a, b;

    for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            a--, b--;
            s.insert(MP(a, b));
        }

    vector <int> min_cost(n, INF);
    vector <bool> used(n, false);

    min_cost[0] = 0;

    double ans = 0;

    for (int i = 0; i < n; i++)
        {
            int v = -1;

            for (int j = 0; j < n; j++)
                {
                    if (!used[j] && (v == -1 || min_cost[j] < min_cost[v]))
                        v = j;
                }
            
            used[v] = true;
         
            ans += sqrt(min_cost[v]);

            for (int j = 0; j < n; j++)
                {
                    if (dist(v, j) < min_cost[j])
                        min_cost[j] = dist(v, j);
                }
        }

    printf("%.5lf", ans);

    return 0;
}
