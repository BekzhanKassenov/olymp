/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n;
    cin >> n;

    int f;
    cin >> f;

    vector <int> a(n - 1);
    for (int& x : a) {
        cin >> x;
    }

    vector <int> idx(n - 1);
    for (int i = 0; i < n - 1; i++) {
        idx[i] = i;
    }

    sort(all(idx), [&a](int i, int j) { return a[i] > a[j]; } );

    vector <pair <int, int> > ans;

    vector <bool> know(n - 1);
    for (int i = 0; i < min(f, n - 1); i++) {
        know[idx[i]] = true;
        ans.emplace_back(1, idx[i] + 2);
    }

    for (int i = 0; i < n - 1; i++) {
        if (!know[idx[i]]) {
            continue;
        }
        
        for (int j = i + 1; j < n - 1 && a[idx[i]] > 0; j++) {
            if (!know[idx[j]]) {
                know[idx[j]] = true;
                a[idx[i]]--;
                ans.emplace_back(idx[i] + 2, idx[j] + 2);
            }
        }
    }

    if (any_of(all(know), [](bool b) { return !b;} )) {
        puts("-1");
        return 0;
    }

    cout << ans.size() << endl;
    for (const auto& p : ans) {
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}
