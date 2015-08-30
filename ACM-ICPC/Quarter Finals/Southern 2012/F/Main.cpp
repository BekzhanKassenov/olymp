/****************************************
**          Solution by NU #2          **
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

typedef struct {
    int cnt;
    int m;
    int sum;
    vector<int> vect; 
} node;

int n, k;
node v[4001];

bool comp(const node &a, const node &b) {
    return a.cnt > b.cnt;
}

bool comp2(const node &a, const node &b) {
    return a.sum > b.sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> n >> k;
    
    for (int i = 0; i < 4001; i++) {
        v[i].cnt = v[i].sum = 0;
        v[i].m = i;
    }

    for (int i = 0; i < n; i++) {
        int m, c;
        cin >> m >> c;
        v[m].vect.push_back(c);
        v[m].cnt++;
    }

    sort(v, v+4001, comp);

    int ans = v[k - 1].cnt, total = 0;

    for (int i = 0; i < 4001; i++) {
        if (v[i].cnt >= ans) {
            total++;
            sort(v[i].vect.begin(), v[i].vect.end());
            reverse(v[i].vect.begin(), v[i].vect.end());
            for (int j = 0; j < min(ans, (int)v[i].vect.size()); j++) {
                v[i].sum += v[i].vect[j];
            }
        }
    }

    sort(v, v + total, comp2);

    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += v[i].sum;
    }

    cout << ans << " " << sum;

    return 0;
}
