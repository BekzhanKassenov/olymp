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
const int MAXN = 1100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

bool add(char encr[], char decr[], int perm[]) {
    if (strlen(encr) != strlen(decr)) {
        return false;
    }

    bool used[26];

    memset(used, false, sizeof used);
    memset(perm, 255, sizeof(int) * 26);

    int n = strlen(encr);

    for (int i = 0; i < n; i++) {
        int d = decr[i] - 'a';
        int e = encr[i] - 'a';

        if (perm[e] == -1 || perm[e] == d) {
            perm[e] = d;
        } else {
            return false;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (perm[i] != -1) {
            if (used[perm[i]]) {
                return false;
            }

            used[perm[i]] = true;
        }
    }

    return true;
}

int T;
int n;
char encr[110][MAXN];
bool can[110];
int perm[110][26];
char decr[MAXN];
char s[MAXN];
char ans[MAXN];
int p[26];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        memset(ans, 0, sizeof(char) * (strlen(s) + 2));
        memset(p, 255, sizeof p);

        scanf("%d\n", &n);

        for (int i = 0; i < n; i++) {
            gets(encr[i]);
        }

        gets(decr);

        bool added = false;
        for (int i = 0; i < n; i++) {
            can[i] = add(encr[i], decr, perm[i]);
            if (can[i]) {
                added = true;
            }
        }

        /*
        for (int i = 0; i < n; i++) {
            if (!can[i]) {
                continue;
            }

            for (int j = 0; j < 26; j++) {
                cout << char(perm[i][j] + 'a') << ' ';
            }
            cout << endl;
        }
        cout << endl;
        */

        gets(s);

        if (!added) {
            puts("IMPOSSIBLE");
            continue;
        }

        set <char> av;
        set <int> S[26];

        for (char cc = 'a'; cc <= 'z'; cc++) {
            av.insert(cc);
        }

        for (int i = 0; i < n; i++) {
            if (can[i]) {
                for (int j = 0; j < 26; j++) {
                    S[j].insert(perm[i][j]);
                }
            }
        }

        while (true) {
            int pos = -1;
            int c = -1;

            for (int i = 0; i < 26; i++) {
                if (S[i].size() == 1u && *S[i].begin() != -1) {
                    pos = i;
                    c = *S[i].begin();
                    break;
                }
            }

            if (pos == -1) {
                break;
            }

            p[pos] = c;

            for (int i = 0; i < 26; i++) {
                if (S[i].count(c)) {
                    S[i].erase(c);
                }
            }

            av.erase(c + 'a');
        }

        for (int i = 0; s[i]; i++) {
            if (p[s[i] - 'a'] != -1) {
                ans[i] = p[s[i] - 'a'] + 'a';
            }
        }
        
        char res = '?';
        if (av.size() == 1u) {
            res = *av.begin();
        }
        for (int i = 0; s[i]; i++) {
            if (ans[i] == '\0') {
                ans[i] = res;
            }
        }

        puts(ans);
    }
    
    return 0;
}
