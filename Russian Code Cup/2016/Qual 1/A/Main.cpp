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

int T;
int a, b, c, d;

bool build(int a, int b, int c, int d, int start, string& s) {
    s.clear();
    s.reserve(a + b + c + d + 1);
    s.push_back(start + '0');

    for (int i = 1; b > 0 || c > 0; i++) {
        if (s.back() == '0') {
            if (b <= 0) {
                return false;
            }

            s.push_back('1');
            b--;
        } else {
            if (c <= 0) {
                return false;
            }

            s.push_back('0');
            c--;
        }
    }

    if (b > 0 || c > 0) {
        return false;
    }

    int pos0 = -1;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            pos0 = i;
        }
    }   

    if (a > 0 && pos0 == -1) {
        return false;
    }   

    if (a > 0) {
        s.insert(pos0, a, '0');
    }

    int pos1 = -1;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            pos1 = i;
        }
    }   

    if (d > 0 && pos1 == -1) {
        return false;
    }   

    if (d > 0) {
        s.insert(pos1, d, '1');
    }

    return true;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);

        string result;
        if (build(a, b, c, d, 0, result)) {
            puts(result.c_str());
        } else if (build(a, b, c, d, 1, result)) {
            puts(result.c_str());
        } else {
            puts("impossible");
        }
    }
    
    return 0;
}
