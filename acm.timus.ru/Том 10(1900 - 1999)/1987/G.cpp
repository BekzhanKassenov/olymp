#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define PII pair <int, int>
#define F first
#define S second

const int maxn = 100010;

int l[maxn], r[maxn];

int a[4 * maxn], t[16 * maxn];

void push(int v, int l, int r) {
    if (l > r || t[v] == -1)
        return;

    if (l == r) {
        a[l] = t[v];
        t[v] = -1;
        return;
    }

    t[v << 1] = t[(v << 1) + 1] = t[v];
    t[v] = -1;
}

void upd(int v, int l, int r, int z_l, int z_r, int val) {
    push(v, l, r);

    if (l > r || z_l > r || z_r < l)
        return;

    if (l >= z_l && r <= z_r) {
        t[v] = val;
        push(v, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    upd(v << 1, l, mid, z_l, z_r, val);
    upd((v << 1) + 1, mid + 1, r, z_l, z_r, val);
}

int get(int v, int l, int r, int ind) {
    push(v, l, r);

    if (l > r || ind < l || ind > r)
        return 0;

    if (l == r)
        return a[l];

    int mid = (l + r) >> 1;

    return (get(v << 1, l, mid, ind) + get((v << 1) + 1, mid + 1, r, ind));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    ios_base :: sync_with_stdio(false);
    int n;

    cin >> n;

    set <int> s;
    map <int, int> Map;

    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        s.insert(l[i]);
        s.insert(r[i]);
    }

    int m;
    cin >> m;
    
    vector <int> zpr(m);
    
    for (int i = 0; i < m; i++) {
        cin >> zpr[i];
        s.insert(zpr[i]);
    }

    int nm = 0;
    for (int i = 0; i < 4 * maxn; i++)
        a[i] = -1;

    for (int i = 0; i < 16 * maxn; i++)
        t[i] = -1;  

    for (set <int> :: iterator it = s.begin(); it != s.end(); it++)
        Map[*it] = nm++;

    int len = s.size(); 

    for (int i = 0; i < n; i++) 
        upd(1, 0, len - 1, Map[l[i]], Map[r[i]], i + 1);

    for (int i = 0; i < m; i++) {
        int q = get(1, 0, len - 1, Map[zpr[i]]);

        cout << q << endl;  
    }

    return 0;
}
