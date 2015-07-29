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
const int BASE = 26 + 26 + 10;
const int MAXN = BASE * BASE + 10;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[5];
vector <int> g[MAXN];
int in[MAXN], out[MAXN];

int codeOf(char c) {
    if (isdigit(c))
        return c - '0';

    if (islower(c))
        return 10 + c - 'a';

    return 36 + c - 'A';
}

char charOf(int a) {
    if (a < 10)
        return a + '0';

    if (a < 36)
        return a + 'a' - 10;

    return a + 'A' - 36;
}

int hash(char a, char b) {
    return codeOf(a) * BASE + codeOf(b);
}

void unhash(int hash, char& a, char& b) {
    b = hash % BASE;
    a = hash / BASE;

    a = charOf(a);
    b = charOf(b);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        gets(s);
        
        int from = hash(s[0], s[1]);
        int to = hash(s[1], s[2]);
        g[from].push_back(to);

        out[from]++;
        in[to]++;
    }

    int start = -1, end = -1;
    for (int i = 0; i < MAXN; i++) {
        if (in[i] - out[i] == 1) {
            if (end != -1) {
                puts("NO");
                return 0;
            }

            end = i;
        } else if (in[i] - out[i] == -1) {
            if (start != -1) {
                puts("NO");
                return 0;
            }

            start = i;
        } else if (in[i] != out[i]) {
            puts("NO");
            return 0;
        }
    }

    if (start == -1 && end == -1) {
        start = 0;
        end = 0;

        while (in[start] == 0) {
            start++;
            end++;
        }

    } else if (start == -1 || end == -1) {
        puts("NO");
        return 0;
    }

    vector <int> st, ans;
    st.push_back(start);

    while (!st.empty()) {
        int v = st.back();
        if (out[v] == 0) {
            st.pop_back();
            ans.push_back(v);
        } else {
            int to = g[v].back();
            g[v].pop_back();
            st.push_back(to);

            out[v]--;
            in[to]--;
        }
    }

    for (int i = 0; i < MAXN; i++) {
        if (in[i] != 0 || out[i] != 0) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    reverse(all(ans));

    char a, b;
    unhash(ans[0], a, b);
    putchar(a);
    putchar(b);

    for (size_t i = 1; i < ans.size(); i++) {
        unhash(ans[i], a, b);
        putchar(b);
    }

    putchar('\n');

    return 0;
}
                        