#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> t;
vector <int> a;
int n;

void init()
{
    t.resize(4 * n + 1);
    a.resize(n);
}

void build(int v, int l, int r)
{
    if (l == r)
        {
            t[v] = a[l];
            return;
        }

    int m = (l + r) / 2;

    build(2 * v, l, m);

    build(2 * v + 1, m + 1, r);

    t[v] = t[2 * v] + t[2 * v + 1];
}

void update(int v, int ind, int l, int r)
{
    if (ind < l || ind > r)
        return;

    if (l == r)
        {
            t[v] = a[l];
            return;
        }

    int m = (l + r) / 2;

    update(2 * v, ind, l, m);

    update(2 * v + 1, ind, m + 1, r);

    t[v] = t[2 * v] + t[2 * v + 1];
}

int get_sum(int v, int _l, int _r, int l, int r)
{
    if (l > r)
        return 0;

    if (l > _r || r < _l)
        return 0;

    if (l >= _l && r <= _r)
        return t[v];

    int m = (l + r) / 2;

    int ans = get_sum(2 * v, _l, _r, l, m) + get_sum(2 * v + 1, _l, _r, m + 1, r);

    return ans;
}


int main()
{
    freopen("in", "r", stdin);

    cin >> n;

    init();

    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);

    int k;

    cin >> k;

    for (int i = 0; i < k; i++)
        {
            int type;

            cin >> type;

            if (type == 1)
                {
                    int val, ind;

                    cin >> ind >> val;

                    a[ind - 1] = val;
                    
                    update(1, ind - 1, 0, n - 1);
                }
            else
                {
                    int left, right;

                    cin >> left >> right;

                    cout << get_sum(1, left - 1, right - 1, 0, n - 1) << endl;
                }
        }

    return 0;
}   
