#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> col;

int get(int v)
{
    if (col[v] == v)
        return v;

    else
        return col[v] = get(col[v]);
}

bool un(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a == b)
        return false;

    col[a] = b;
    return true;
}

struct edge
{
    int from, to, cost;

    edge () {}

    edge(int f, int t, int c) 
        {
            from = f;
            to = t;
            cost = c;
        }

};

bool operator < (const edge a, const edge b)
{
    if (a.cost < b.cost)
        return true;

    return false;
}


int main()
{   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    vector <vector <int> > g(n, vector <int> (n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> g[i][j];

    vector <edge> a;

    for (int i = 0; i < n; i++)     
        {
            for (int j = i + 1; j < n; j++)
                a.push_back(edge(i, j, g[i][j]));
        }

    sort(a.begin(), a.end());

    col.resize(n);

    for (int i = 0; i < n; i++) 
        col[i] = i;

    int ans = 0;

    for (int i = 0; i < (int)a.size(); i++)
        {
            //cout << a[i].from << ' ' << a[i].to << ' ' << a[i].cost << endl;
            if (un(a[i].from, a[i].to))
                ans += a[i].cost;
        }

    cout << ans;    
}
