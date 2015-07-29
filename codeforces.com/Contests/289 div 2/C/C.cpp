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
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
string cur;

string get_next(const string& prev, int prevsum, int sum) {
    int cnt = (sum + 8) / 9;
    string result;
    
    if (cnt > (int)prev.size()) {
        result.append(sum / 9, '9');
        if (sum % 9 != 0) {
            result.append(1, '0' + sum % 9);
        }
    } else {
        if (prevsum < sum) {
            result = prev;
            sum -= prevsum;

            for (int i = result.size() - 1; i >= 0; i--) {
                int diff = '9' - result[i];

                if (diff > sum) {
                    diff = sum;
                }

                result[i] += diff;
                sum -= diff;
            }

            result.append(sum / 9, '9');
            if (sum % 9 != 0) {
                result.append(1, '0' + sum % 9);
            }
        } else {

        }
    }

    sort(all(result));
    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        cur = get_next(cur, a[i - 1], a[i]);
        puts(cur.c_str());
    }

    return 0;
}
