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
vector <int> ans;
vector <int> neg;
double a[MAXN];

bool cmp(int l, int r) {
    return a[l] < a[r];
}

bool all_bad() {
    for (int i = 0; i < n; i++) {
        if (a[i] > 1 || a[i] < - 1) {
            return false;
        }
    }

    return true;
}

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

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] > 1) {
            ans.push_back(i + 1);
        } else if (a[i] < 0) {
            neg.push_back(i);
        }
    }

    if (all_zero()) {
        cout << 0 << endl;
        return 0;

    }
    
    if (all_bad()) {
        double mul = *max_element(a, a + n);
        ans.clear();
        ans.push_back(max_element(a, a + n) - a + 1);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] * a[j] > mul) {
                    mul = a[i] * a[j];
                    ans.clear();

                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                }
            }
        }
    } else {
        sort(all(neg), cmp);

        double mul = 0;

        cerr << "beka" << endl;

        for (size_t i = 0; i + 1 < neg.size(); i += 2) {
            if (a[neg[i]] * a[neg[i + 1]] > 1.0) {
                ans.push_back(neg[i] + 1);
                ans.push_back(neg[i + 1] + 1);

                if (mul == 0) {
                    mul = a[neg[i]] * a[neg[i + 1]];
                } else {
                    mul *= a[neg[i]] * a[neg[i + 1]];
                }
            }
        }

        if (mul == 0) {
            for (size_t i = 0; i + 1 < neg.size(); i += 2) {
                if (a[neg[i]] * a[neg[i + 1]] > mul) {
                    ans.clear();
                    mul = a[neg[i]] * a[neg[i + 1]];

                    ans.push_back(neg[i] + 1);
                    ans.push_back(neg[i + 1] + 1);
                }
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
