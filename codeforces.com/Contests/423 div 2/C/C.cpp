/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1100000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char mem[2 * MAXN];
char* memptr = mem;
char* s[MAXN];
int len[MAXN];

void reads(int i) {
    scanf("\n%s", memptr);
    s[i] = memptr;
    len[i] = strlen(s[i]);
    memptr = memptr + (len[i] + 1);
}

int n;
char res[2 * MAXN];
vector <char*> open[2 * MAXN];
vector <pair <int, char*> > close[2 * MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    int total = 0, k, x;
    for (int i = 0; i < n; i++) {
        reads(i);
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            x--;
            open[x].push_back(s[i]);
            close[x + len[i] - 1].push_back(make_pair(x, s[i]));
            total = max(total, x + len[i] - 1);
        }
    }

    multiset <pair <int, char*> > cur;
    for (int i = 0; i <= total; i++) {
        for (char* ptr : open[i]) {
            cur.emplace(i, ptr);
        }

        if (!cur.empty()) {
            pair <int, char*> some = *cur.begin();
            char c = some.second[i - some.first];
            res[i] = c;
        } else {
            res[i] = 'a';
        }

        for (auto p : close[i]) {
            cur.erase(cur.find(p));
        }
    }
    
    puts(res);

    return 0;
}
