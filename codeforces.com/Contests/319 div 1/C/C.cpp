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
const int TRIALS = 10;
const int LEN = 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int x[MAXN], y[MAXN];

int fastAbs(int n) { return (n ^ (n >> 31)) - (n >> 31); }

int dist(int a, int b) {
    return fastAbs(x[a] - x[b]) + fastAbs(y[a] - y[b]);
}

long long dist(int *arr, int len) {
    long long res = 0;

    for (int i = 0; i + 1 < len; i++) {
        res += dist(arr[i], arr[i + 1]);
    }

    return res;
}

//vec.size() <= 10
void solve(int *arr, int len) {
    long long d = dist(arr, len);

    for (int i = 0; i < TRIALS; i++) {
        int a = rand() % len;
        int b = rand() % len;

        if (abs(a - b) <= 1) {
            continue;
        }

        long long td = d;
        
        if (a > 0) {
            td -= dist(arr[a - 1], a);
        }

        if (a < len - 1) {
            td -= dist(arr[a], arr[a + 1]);
        }

        if (b > 0) {
            td -= dist(arr[b - 1], b);
        }

        if (b < len - 1) {
            td -= dist(arr[b], arr[b + 1]);
        }

        swap(arr[a], arr[b]);

        if (a > 0) {
            td += dist(arr[a - 1], a);
        }

        if (a < len - 1) {
            td += dist(arr[a], arr[a + 1]);
        }

        if (b > 0) {
            td += dist(arr[b - 1], b);
        }

        if (b < len - 1) {
            td += dist(arr[b], arr[b + 1]);
        }

        if (td < d) {
            d = td;
        } else {
            swap(arr[a], arr[b]);
        }
    }
}

bool cmp_x(int a, int b) {
    return x[a] < x[b];
}

bool cmp_y(int a, int b) {
    return y[a] < y[b];
}

void go(int *arr, int len) {
    if (len <= LEN) {
        solve(arr, len);
        return;
    }

    sort(arr, arr + len, cmp_x);

    int half = len / 2;

    sort(arr, arr + half, cmp_y);
    sort(arr + half, arr + len, cmp_y);
    reverse(arr + half, arr + len);

    int size1 = half / 2;
    int size2 = half - size1;
    int size3 = (len - half) / 2;
    int size4 = len - half - size3;

    int *ptr1 = arr;
    int *ptr2 = arr + size1;
    int *ptr3 = arr + len;
    int *ptr4 = arr + len + size3;

    go(ptr1, size1);
    go(ptr2, size2);
    go(ptr3, size3);
    go(ptr4, size4);
}

int a[MAXN];
stringstream ss;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    double start = clock();
#endif

    srand(0xbeef);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = i;
    }

    go(a, n);

    for (int i = 0; i < n; i++) {
        ss << a[i] + 1 << ' ';
    }
    
    cout << ss.str() << endl;
    
#ifndef ONLINE_JUDGE
    cerr << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl;
#endif    
    return 0;
}
