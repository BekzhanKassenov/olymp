/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "permutation"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int N = 5;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <int> operator * (const vector <int>& a, const vector <int>& b) {
    vector <int> c(N);

    for (int i = 0; i < N; i++) {
        c[i] = a[b[i]];
    }

    return c;
}

bool simple(const vector <int>& a) {
    for (int i = 0; i < N; i++) {
        int p = a[i];

        if (a[p] != i) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen(File".in", "r", stdin);
    
    vector <int> a(N), b(N);

    for (int i = 0; i < N; i++) {
        a[i] = i;
    }

    do {
        for (int i = 0; i < N; i++) {
            b[i] = i;
        }

        do {
            if (!simple(b)) {
                continue;
            }
            
            vector <int> c = a * b;

            for (int i = 0; i < N; i++) {
                cout << a[i] << " \n"[i == N - 1];
            }

            for (int i = 0; i < N; i++) {
                cout << b[i] << " \n"[i == N - 1];
            }

            for (int i = 0; i < N; i++) {
                cout << c[i] << " \n"[i == N - 1];
            }
            cout << endl;
        } while (next_permutation(all(b)));
    } while (next_permutation(all(a)));

    return 0;
}
