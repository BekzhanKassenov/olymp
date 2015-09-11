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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int x[MAXN], y[MAXN];

bool cmp(int a, int b) {
    return y[a] < y[b];
}

vector <int> vec[MAXN];
stringstream ss;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    double start = clock();
#endif

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        vec[x[i] / 1000].push_back(i);
    }

    for (int i = 0; i < MAXN; i++) { 
        sort(all(vec[i]), cmp);
    }

    for (int i = 0; i < MAXN; i++) {
        if (i & 1) {
            reverse(all(vec[i]));
        }

        for (int idx: vec[i]) {
            ss << idx + 1 << ' ';
        }
    }

    cout << ss.str() << endl;
    
#ifndef ONLINE_JUDGE
    cerr << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl;
#endif    
    return 0;
}
