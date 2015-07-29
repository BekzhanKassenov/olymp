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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Declaration {
    char var;
    int row, col;

    Declaration() { }

    Declaration(char var, int row, int col) : var(var), row(row), col(col) { }

    bool operator < (const Declaration& d) const {
        return var < d.var;
    }
};

const set <Declaration> EMPTY;
int n;
char s[100];
vector <set <Declaration> > st;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    st.push_back(EMPTY);

    scanf("%d\n", &n);

    for (int row = 1; row <= n; row++) {
        gets(s);

        for (int col = 0; s[col]; col++) {
            if (islower(s[col])) {
                Declaration cur(s[col], row, col + 1);
                st.back().insert(cur);

                int pos = st.size() - 2;

                for (int i = pos; i >= 0; i--) {
                    set <Declaration> :: iterator it = st[i].find(cur);
                    
                    if (it != st[i].end()) {
                        printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n", row, col + 1, s[col], it -> row, it -> col);
                        break;
                    }
                }

            } else if (s[col] == '{') {
                st.push_back(EMPTY);
            } else if (s[col] == '}') {
                st.pop_back();
            }
        }
    }
    
    return 0;
}
