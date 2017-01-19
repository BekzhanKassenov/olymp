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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN];
int ans[256];

int cnt(int l) {
    if (l < 0 || l + 3 >= n) {
        return -1;
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (s[i + l] == '!') {
            ans++;
        }
    }

    return ans;
}

bool fix(int l) {
    int pos = -1;
    for (int i = 0; i < 4; i++) {
        if (s[i + l] == '!') {
            pos = l + i;
            break;
        }
    }

    if (pos == -1) {
        return false;
    }

    for (char c : { 'R', 'B', 'Y', 'G'} ) {
        bool ok = true;
        for (int i = 0; i < 4; i++) {
            if (s[i + l] == c) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans[c]++;
            s[pos] = c;
            break;
        }
    }

    return true;
}

bool used[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);

    queue <int> q;
    for (int i = 0; i < n; i++) {
         if (cnt(i) == 1) {
            q.push(i);
            used[i] = true;
         }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (!fix(v)) {
            continue;
        }

        for (int i = v - 5; i < v + 5; i++) {
            if (i >= 0 && cnt(i) == 1 && !used[i]) {
                used[i] = true;
                q.push(i);
            }
        }
    }

    for (char c : { 'R', 'B', 'Y', 'G'}) {
        printf("%d ", ans[c]);
    }

    return 0;
}
