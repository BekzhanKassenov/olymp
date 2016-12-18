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
const int MAXN = 1010;
const int MAXQ = 21;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int ans[MAXN];

void doQuery(vector <int>& query) {
    static int resp[MAXN];
    
    sort(all(query));

    cout << query.size() << endl;
    for (int x : query) {
        cout << x + 1 << ' ';
    }
    cout << endl << flush;

    for (int i = 0; i < n; i++) {
        cin >> resp[i];
    }

    for (int i = 0; i < n; i++) {
        if (!binary_search(all(query), i)) {
            ans[i] = min(ans[i], resp[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        ans[i] = INF;
    }

    for (int q = 0; (1 << q) < n; q++) {
        vector <int> query1, query2;
        for (int i = 0; i < n; i++) {
            if (i & (1 << q)) {
                query1.push_back(i);
            } else {
                query2.push_back(i);
            }
        }

        doQuery(query1);
        doQuery(query2);
    }

    cout << -1 << endl;
    for (int i = 0; i < n; i++)  {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}
