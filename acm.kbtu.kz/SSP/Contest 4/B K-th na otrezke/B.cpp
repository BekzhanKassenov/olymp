#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector <int> a;
vector < vector <int> > t;

void build(int v, int l, int r)
{
    vector <int> ans;
    if (l >= r)
        {
            t[v].push_back(a[r]);
            return;
        }
    int m = (l + r) / 2;
    build (v * 2, l, m);
    build (v * 2 + 1, m + 1, r);
    merge(t[2 * v].begin(),t[2 * v].end(), t[2 * v + 1].begin(), t[2 * v + 1].end(), t[v].begin());
}

int get_ans(int v, int k, int l, int r, )
{
    if (t[v].size() == 1)
        return t[v][0];
    if (t[2 * v].size() < k)
            return get_ans(v * 2 + 1, k - t[2 * v].size(), m + 1, r);
    else    
        return get_ans(v * 2, k, l, m);
}

int main()
{
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    a.resize(n + 1);
    t.resize(4 * n + 12);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int x, y, z;
    for (int i = 0; i < m; i++)
        {   
            cin >> x >> y >> z;
            cout << get_ans(1, x, y, z) << endl;
        }
    return 0;
}
