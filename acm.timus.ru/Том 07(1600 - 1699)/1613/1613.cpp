#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <vector <int> > tree;

vector <int> a;

void merge(int l, int r, int v)
{
    int uk1 = 0;
    int uk2 = 0;

    int s1 = tree[l].size();
    int s2 = tree[r].size();

    for (;;)
        {
            if (uk1 == s1 && uk2 == s2)
                break;

            if (uk1 == s1)
                {   
                    tree[v].push_back(tree[r][uk2++]);
                    continue;
                }

            if (uk2 == s2)
                {
                    tree[v].push_back(tree[l][uk1++]);
                    continue;
                }   

            if (tree[l][uk1] < tree[r][uk2])
                tree[v].push_back(tree[l][uk1++]);
            else
                tree[v].push_back(tree[r][uk2++]);  
        }
}

void build(int v, int l, int r)
{
    if (l > r)
        return;

    if (l == r)
        {
            tree[v].push_back(a[l]);
            return;
        }

    int m = (l + r) >> 1;

    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    merge(2 * v, 2 * v + 1, v); 
}

bool get_ans(int v, int cur_l, int cur_r, int l, int r, int cnt)
{
    if (cur_l > cur_r)
        return false;

    if (cur_r < l || cur_l > r)
        return false;

    if (l == r)
        if (a[l] == cnt)
            return true;
        else
            return false;

    if (cur_l == cur_r)
        if (a[cur_l] == cnt)
            return true;
        else
            return false;

    if (cur_l >= l && cur_r <= r)
        {
            return binary_search(tree[v].begin(), tree[v].end(), cnt);
        }

    int m = (cur_l + cur_r) >> 1;

    return (get_ans(2 * v, cur_l, m, l, r, cnt) || (get_ans(2 * v + 1, m + 1, cur_r, l, r, cnt)));
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int n;

    scanf("%d", &n);

    a.resize(n);

    tree.resize(4 * n + 1);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    build(1, 0, n - 1);

    int m;

    scanf("%d", &m);

    string ans;

    for (int i = 0; i < m; i++)
        {
            int l, r, cnt;

            scanf("%d%d%d", &l, &r, &cnt);

            l--, r--;

            if (get_ans(1, 0, n - 1, l, r, cnt))
                ans += '1';
            else
                ans += '0'; 

        }

    cout << ans;

    return 0;
}
