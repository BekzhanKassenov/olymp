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
const int BASE = 10010;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;

struct Word {
    char first;
    char last;
    int cnt[26];
    int len;
    string str;
    ull h;

    Word() :
      first(0),
      last(0),
      len(0),
      h(0) {
        memset(cnt, 0, sizeof cnt);
    }

    void build() {
        len = str.size();
        first = str[0];
        last = 0;
        h = 0;

        if (len > 1) {
            last = str.back();
        }

        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
        }

        for (int i = 1; i + 1 < len; i++) {
            cnt[str[i] - 'a']++;
        }

        rehash();
    }

    void rehash() {
        h = first * BASE + last;

        for (int i = 0; i < 26; i++) {
            h *= BASE;
            h += cnt[i];
        }
    }

    void print() {
        cout << "FIRST: " << first << " LAST: " << last << " LENGTH: " << len << endl;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                cout << char(i + 'A') << "x" << cnt[i] << ' ';
            }
        }
        cout << endl;
    }
};

struct Compare {
    bool operator () (Word* w1, Word* w2) const {
        if (w1->h != w2->h) {
            return w1->h < w2->h;
        }

        if (w1->len != w2->len) {
            return w1->len < w2->len;
        }

        if (w1->first != w2->first) {
            return w1->first < w2->first;
        }

        if (w1->last != w2->last) {
            return w1->last < w2->last;
        }

        for (int i = 0; i < 26; i++) {
            if (w1->cnt[i] != w2->cnt[i]) {
                return w1->cnt[i] < w2->cnt[i];
            }
        }

        return false;
    }
};

int n;
Word w[100010];
map <Word*, int, Compare> Map;
char s[MAXN];
int cnt[MAXN][26];
int can[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> T;

    while (T--) {
        Map.clear();

        cin >> s;
        cin >> n;

        int len = strlen(s);

        for (int i = 0; i < n; i++) {
            cin >> w[i].str;
            w[i].build();
            Map[&w[i]]++;
        }

        memset(cnt[0], 0, sizeof(int) * 26);
        cnt[0][s[0] - 'a'] = 1;
        
        for (int i = 1; i < len; i++) {
            memcpy(cnt[i], cnt[i - 1], sizeof(int) * 26);
            cnt[i][s[i] - 'a']++;
        }

        for (int i = 0; i < len; i++) {
            Word wrd;
            wrd.first = s[i];
            wrd.rehash();

            wrd.len = 1;

            if (Map.count(&wrd)) {
                can[i][i + 1] = Map[&wrd];
            }
        }

        for (int i = 0; i < len; i++) {
            for (int j = i + 2; j <= len; j++) {
                Word wrd;

                wrd.first = s[i];
                wrd.last = s[j - 1];

                memcpy(wrd.cnt, cnt[j - 2], sizeof(int) * 26);
                for (int k = 0; k < 26; k++) {
                    wrd.cnt[k] -= cnt[i][k];
                }

                wrd.len = j - i;

                wrd.rehash();

                wrd.print();

                if (Map.count(&wrd)) {
                    can[i][j] = Map[&wrd];
                }
            }
        }

        int paths = bfs(0, len);

        if (paths == 0) {

        } else if (paths == 1) {

        } else {

        }
    }
    
    return 0;
}
