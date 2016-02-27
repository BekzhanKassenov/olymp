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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int idx(int i, int j) {
    return i * n + j;
}

struct Permutation {
    vector <int> vec;

    Permutation() {
        vec.resize(n * n);
        for (int i = 0; i < n * n; i++) {
            vec[i] = i;
        }
    }

    Permutation(char dir, int num) {
        vec.resize(n * n);
        for (int i = 0; i < n * n; i++) {
            vec[i] = i;
        }

        int save = 0;
        switch (dir) {
            case 'L':
                save = vec[idx(num, 0)];
                for (int j = 0; j < n - 1; j++) {
                    vec[idx(num, j)] = vec[idx(num, j + 1)];
                }

                vec[idx(num, n - 1)] = save;
                break;

            case 'R':
                save = vec[idx(num, n - 1)];
                for (int j = n - 1; j > 0; j--) {
                    vec[idx(num, j)] = vec[idx(num, j - 1)];
                }

                vec[idx(num, 0)] = save;
                break;

            case 'U':
                save = vec[idx(0, num)];
                for (int i = 0; i < n - 1; i++) {
                    vec[idx(i, num)] = vec[idx(i + 1, num)];
                }

                vec[idx(n - 1, num)] = save;
                break;

            case 'D':
                save = vec[idx(n - 1, num)];
                for (int i = n - 1; i > 0; i--) {
                    vec[idx(i, num)] = vec[idx(i - 1, num)];
                }

                vec[idx(0, num)] = save;
                break;

            default:
                break;
        }
    }

    int& operator [] (int pos) {
        return vec[pos];
    }

    const int& operator[] (int pos) const {
        return vec[pos];
    }

    void print() const {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", vec[idx(i, j)] + 1);
            }
            
            puts("");
        }
    }
};

void apply(Permutation& a, const Permutation& b) {
    static Permutation result;
    for (int i = 0; i < n * n; i++) {
        result[i] = a[b[i]]; 
    }

    a.vec.swap(result.vec);
}

void binpow(Permutation& a, int p) {
    static Permutation result;
    for (int i = 0; i < n * n; i++) {
        result[i] = i;
    }

    while (p > 0) {
        if (p & 1) {
            apply(result, a);
        }

        apply(a, a);
        p >>= 1;
    }

    a.vec.swap(result.vec);
}

int l;
char s[MAXN];
int pos;

int parseInt() {
    int result = 0;
    while (pos < l && isdigit(s[pos])) {
        result *= 10;
        result += s[pos] - '0';
        pos++;
    }

    return result;
}

Permutation seq();
Permutation op();
Permutation rep();

Permutation op() {
    char shift = s[pos];
    pos++;
    int num = parseInt();

    return Permutation(shift, num - 1);
}

Permutation rep() {
    pos++; // skip '(';
    Permutation perm = seq();
    pos++; // skip ')';

    int p = parseInt();

    binpow(perm, p);

    return perm;
}

Permutation seq() {
    Permutation result;
    while (pos < l && s[pos] != ')') {
        if (s[pos] == 'L' || s[pos] == 'R' || s[pos] == 'U' || s[pos] == 'D') {
            apply(result, op());
        } else if (s[pos] == '(') {
            apply(result, rep());
        } else {
            assert(false);
        }
    }

    return result;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &l);
    gets(s);

    Permutation result;
    apply(result, seq());

    result.print();

    return 0;
}
