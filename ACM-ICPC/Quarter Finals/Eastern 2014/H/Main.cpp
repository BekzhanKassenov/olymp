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
char s[MAXN];
vector <int> st;
int num[MAXN];
int low, up;
int ans[MAXN];

bool is_pair(char c1, char c2) {
    return c1 != c2 && tolower(c1) == tolower(c2);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);

    for (int i = 0; i < 2 * n; i++) {
        if (islower(s[i])) {
            num[i] = low++;
        } else {
            num[i] = up++;
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (st.empty()) {
            st.push_back(i);
        } else {
            if (is_pair(s[st.back()], s[i])) {
                if (isupper(s[st.back()])) {
                    ans[num[st.back()]] = num[i];
                } else {
                    ans[num[i]] = num[st.back()];
                }

                st.pop_back();
            } else {
                st.push_back(i);
            }
        }
    }

    if (!st.empty()) {
        puts("Impossible");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i] + 1);
        }
    }

    return 0;
}
