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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
long long a[MAXN];
bool used[MAXN];

void skipSpaces() {
    while (isspace(cin.peek())) {
        cin.get();
    }
}

void read() {
    cin >> n >> k;
    skipSpaces();

    for (int i = 0; i < n; i++) {
        if (cin.peek() == '?') {
            used[i] = true;
            cin.get();
        } else {
            cin >> a[i];
        }

        skipSpaces();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    read();
    
    long long cursum = 0;
    for (int i = 0; i < k; i++) {
        if (!used[i]) {
            cursum += a[i];
        }
    }

    for (int i = k; i < n; i++) {
        int left = i - k;
        int right = i;

        if (used[left] && used[right]) {
            used[left] = false;
            used[right] = false;
            a[left] = 0;
            a[right] = 1;
        } else if (used[left]) {
            used[left] = false;
            a[left] = 0;
        } else if (used[right]) {
            used[right] = 0;
            a[right] = a[left] + 1;
        } else {
            if (cursum - a[left] + a[right] <= cursum) {
                puts("Incorrect sequence");
                return 0;
            }

            cursum -= a[left];
            cursum += a[right];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}
