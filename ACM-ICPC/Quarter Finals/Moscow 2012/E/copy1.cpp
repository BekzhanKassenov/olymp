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
vector <double > a;
vector <int> ans;
double res = 0;

bool all_zero() {
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            return false;
        }
    }   

    return true;
}


int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (all_zero()) {
        cout << 0 << endl;
        return 0;

    }

    sort(all(a));

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] > 1) {
            if (res == 0) res = 1;
            res *= a[i];
            ans.push_back(a[i]);
            swap(a[i], a.back());
            a.pop_back();
        }
    }

    vector <double > tmp_negative;
    for (size_t i = 0; i < a.size() - 1; i++) {
        if (a[i] < -1) {
            tmp_negative.push_back(a[i]);
            swap(a[i], a.back());
            a.pop_back();
        }
    }

    sort (all(tmp_negative));

    if (tmp_negative.size() >= 2) {
        for (size_t i = tmp_negative.size() - 1; i > 0; i -= 2) {
           if (res == 0) res = 1;
           res *= tmp_negative[i];
           res *= tmp_negative[i - 1];
           ans.push_back(tmp_negative[i]);
           ans.push_back(tmp_negative[i - 1]);
        }
    }




    if (a.size() >= 2){
    for (size_t i = 0; i < a.size() - 1; i += 2) {
        double tmp = a[i] * a[i + 1];

        if (res == 0 || res * tmp > res) {
            if (res == 0) res = 1;
            ans.push_back(a[i]);
            ans.push_back(a[i + 1]);
            res *= a[i];
            res *= a[i + 1];
            swap(a[i], a.back());
            a.pop_back();
            swap(a[i + 1], a.back());
            a.pop_back();
        }
    }
    }
    if (a.size() >= 2) {
    for (size_t i = a.size() - 1; i > 0; i -= 2) {
        double tmp = a[i] * a[i - 1];

        if (res == 0 || res * tmp > res) {
            if (res == 0) res = 1;
            ans.push_back(a[i]);
            ans.push_back(a[i - 1]);
            res *= a[i];
            res *= a[i - 1];
            swap(a[i], a.back());
            a.pop_back();
            swap(a[i - 1], a.back());
            a.pop_back();
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
