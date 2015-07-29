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
const int MAXN = 125;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

map <string, int> Map;
string back[MAXN];
int dist[MAXN][MAXN];

int sign(int n) {
    return (n > 0) - (n < 0);
}

int get_dist(const string& s, const string& t) {
    int res = 0;

    for (char c = 'A'; c <= 'E'; c++) {
        for (char d = c + 1; d <= 'E'; d++) {

            int possc = 0;
            int possd = 0;
            int postc = 0;
            int postd = 0;

            for (int i = 0; i < 5; i++) {
                if (s[i] == c) {
                    possc = i;
                }

                if (s[i] == d) {
                    possd = i;
                }

                if (t[i] == c) {
                    postc = i;
                }

                if (t[i] == d) {
                    postd = i;
                }
            }

            if (sign(possc - possd) != sign(postc - postd)) {
                res++;
            }
        }
    }

    return res;
}

void precalc() {
    string s;

    for (int i = 0; i < 5; i++) {
        s += 'A' + i;
    }

    int cnt = 0;

    do {
        Map[s] = cnt;
        back[cnt] = s;
        cnt++;
    } while (next_permutation(all(s)));

    for (int i = 0; i < 5; i++) {
        s[i] = 'A' + i;
    }

    do {
        string t;

        for (int i = 0; i < 5; i++) {
            t += 'A' + i;
        }

        do {
            dist[Map[s]][Map[t]] = get_dist(s, t);
        } while (next_permutation(all(t)));
    } while (next_permutation(all(s)));
}

int n;
char s[7];
int a[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    precalc();
    
    for (scanf("%d\n", &n); n != 0; scanf("%d\n", &n)) {
        for (int i = 0; i < n; i++) {
            gets(s);
            a[i] = Map[s];
        }

        int ans = INF;
        string res;

        for (int i = 0; i < 120; i++) {
            int sum = 0;

            for (int j = 0; j < n; j++) {
                sum += dist[i][a[j]];
            }

            if (sum < ans) {
                ans = sum;
                res = back[i];
            }
            
            //cerr << sum << ' ' << back[i] << endl;
        }

        printf("%s is the median ranking with value %d.\n", res.c_str(), ans);
    }

    return 0;
}
