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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, a, b, k;
char s[MAXN];
vector <pair <int, int> > seg;

int len(const pair <int, int>& p) {
    return p.second - p.first + 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d\n", &n, &a, &b, &k);
    gets(s);

    pair <int, int> cur(0, 0);
    int sum = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '1') {
            if (len(cur) >= b) {
                seg.push_back(cur);
                sum += len(cur) / b;
            }
            cur.first = cur.second = i;
        } else {
            cur.second = i;
        }   
    }
    if (len(cur) >= b) {
        seg.push_back(cur);
        sum += len(cur) / b;
    }

    if (sum > a) {
        puts("0");
        return 0;
    }

    vector <int> ans;
    for (const auto& s : seg) {
        for (int i = len(s) % b; i < b; i++) {
            for (int j = s.first + i; j <= s.second; j += 2) {
                ans.push_back(j);
            }
        }
    }

    printf("%d\n", (int)ans.size());
    for (int x : ans) {
        printf("%d ", x);
    }
    puts("");

    return 0;
}
