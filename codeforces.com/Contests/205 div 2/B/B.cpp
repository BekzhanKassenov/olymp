/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define y0 y0_lal
#define y1 y1_lal
#define yn en_lal
#define j0 j0_lal
#define j1 j1_lal
#define jn jn_lal
#define next next_lal
#define prev prev_lal

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

VI cnt[100];
bool used[100];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    int n;

    cin >> n;

    VI a(2 * n);

    set <int> s;

    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        cnt[a[i]].push_back(i);
    }

    VI mn1, mn2;

    int c = 0;

    for (int i = 0; i < 100; i++) {
        if (cnt[i].size() > 1) {
            mn1.push_back(cnt[i].back());
            cnt[i].pop_back();
            mn2.push_back(cnt[i].back());
            cnt[i].pop_back();
            used[i] = true;
            c++;
        }
    }

    vector <int> cur;

    for (int i = 0; i < 100; i++) {
        if (cnt[i].size() == 1 && !used[i]) {
            cur.push_back(cnt[i][0]);
            cnt[i].pop_back();
        }   
    }

    int cnt1 = cur.size() / 2;
    int cnt2 = cur.size() - cnt1;

    cout << (c + cnt1) * (c + cnt2) << endl;

    for (int i = 0; i < cnt1; i++) {
        mn1.push_back(cur.back());
        cur.pop_back();
    }

    while (!cur.empty()) {
        mn2.push_back(cur.back());
        cur.pop_back();
    }

    for (int i = 0; i < 100; i++) {
        while (!cnt[i].empty()) {
            if ((int)mn1.size() < n) 
                mn1.push_back(cnt[i].back());
            else
                mn2.push_back(cnt[i].back());

            cnt[i].pop_back();
        }
    }

    for (int i = 0; i < n; i++)
        a[mn1[i]] = 1;

    for (int i = 0; i < n; i++)
        a[mn2[i]] = 2;

    for (int i = 0; i < 2 * n; i++)
        cout << a[i] << ' ';    

    return 0;
}
