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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <pair<long long, int> > a;
vector <int> ans;
double res = 0;
bool was = false;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        x *= 100.0;

        a[i].first = (long long)x;
        a[i].second = i + 1;

    }

    sort(all(a));

    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i].first > 100) {
            ans.push_back(a[i].second);
            was = true;    
        }
        else {
            break;
        }
    }

    for (int i = 0; i + 1 < a.size(); i+=2) {
        if (a[i].first < 0 && a[i + 1].first < 0 && a[i].first * a[i + 1].first > 10000) {
            ans.push_back(a[i].second);
            ans.push_back(a[i + 1].second);
            was = true;
        }    
    }

    if (!was) {
        if (a.size() < 2) {
            ans.push_back(a.back().first);
        }
        else {
            if (a.back().first * 100 >= a[0].first * a[1].first) {
                ans.push_back(a.back().second);
            }
            else {
                ans.push_back(a[0].second);
                ans.push_back(a[1].second);
            }
        }
    }

    sort(all(ans));

    cout << ans.size() << endl;

    for (int x: ans) {
        cout << x << ' ';
    }
    cout << endl;
    
    return 0;
}
