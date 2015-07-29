// This solution based on Segment tree

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define INF (int)2e9

struct ver
{
    int mx, mn;

    ver() : mx(0), mn(INF) {}
};

int a[100002];

vector <ver> t;

void build(int v, int l, int r)
{
    if (l > r)
        return;

    if (l == r)
        {
            t[v].mn = t[v].mx = a[l];
            return;
        }   

    int tw = v << 1;

    int m = (l + r) >> 1;

    build(tw, l, m);
    build(tw + 1, m + 1, r);

    t[v].mn = min(t[tw].mn, t[tw + 1].mn);
    t[v].mx = max(t[tw].mx, t[tw + 1].mx);
}

void upd(int v, int l, int r, int ind)
{
    if (l > r)
        return;

    if (ind < l || ind > r)
        return;

    if (l == r)
        {
            t[v].mn = t[v].mx = a[l];
            return; 
        }

    int tw = v << 1;

    int m = (l + r) >> 1;

    upd(tw, l, m, ind);
    upd(tw + 1, m + 1, r, ind);

    t[v].mn = min(t[tw].mn, t[tw + 1].mn);
    t[v].mx = max(t[tw].mx, t[tw + 1].mx);
}

int get_min(int v, int cur_l, int cur_r, int l, int r)
{
    if (cur_l > cur_r)
        return INF;

    if (cur_l == cur_r)
        {
            if (cur_l >= l && cur_l <= r)
                return t[v].mn;
            return INF;
        }

    if (l > cur_r || r < cur_l)
        return INF;

    if (cur_l >= l && cur_r <= r)
        return t[v].mn;

    int tw = v << 1;

    int m = (cur_l + cur_r) >> 1;

    return (min(get_min(tw, cur_l, m, l, r), get_min(tw + 1, m + 1, cur_r, l, r)));
}

int get_max(int v, int cur_l, int cur_r, int l, int r)
{
    if (cur_l > cur_r)
        return -INF;

    if (cur_l == cur_r)
        {
            if (cur_l >= l && cur_l <= r)
                return t[v].mx;
            return -INF;
        }

    if (l > cur_r || r < cur_l)
        return -INF;

    if (cur_l >= l && cur_r <= r)
        return t[v].mx;

    int tw = v << 1;

    int m = (cur_l + cur_r) >> 1;

    return (max(get_max(tw, cur_l, m, l, r), get_max(tw + 1, m + 1, cur_r, l, r)));
}

int get_ans(int l, int r)
{
    if (l == r)
        return 0;

    return get_max(1, 0, 100000, l, r) - get_min(1, 0, 100000, l, r);
}

int main()
{
    freopen("rvq.in", "r", stdin);
    freopen("rvq.out", "w", stdout);

    int k;

    cin >> k;

    t.resize(400000);

    for (int i = 0; i < 100001; i++)
        {
            int sq = (i + 1) % 12345;

            sq = (sq * sq) % 12345;

            int cb = (i + 1) % 23456;

            cb = (((cb * cb) % 23456) * cb) % 23456;

            a[i] = sq + cb;
        }

    build(1, 0, 100000);

    for (int i = 0; i < k; i++)
        {
            int x, y;

            cin >> x >> y;

            if (x > 0)
                {
                    cout << get_ans(x - 1, y - 1) << endl;
                }
            else
                {
                    x *= -1;
                    x--;
                    a[x] = y;
                    upd(1, 0, 100000, x);
                }   
        }

    return 0;
}