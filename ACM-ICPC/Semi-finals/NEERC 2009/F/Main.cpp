/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "funny"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXM = 1010;
const int BASE = 27;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int cnt[MAXM][26];
string input[MAXM];
priority_queue <pair <int, int>,
                vector <pair <int, int> >,
                greater <pair <int, int> > > q;

string unhash(int h) {
    string result;
    while (h > 0) {
        result.append(1, h % BASE + 'A' - 1);
        h /= BASE;
    }

    reverse(all(result));

    return result;
}

bool check(const string& s, int cnt[]) {
    static int scnt[26];
    memset(scnt, 0, sizeof scnt);

    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        scnt[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (scnt[i] > cnt[i]) {
            return false;
        }
    }

    return true;
}

void add(const string &s, int h) {
    pair <int, int> res;
    res.second = h;

    for (int i = 0; i < m; i++) {
        if (s == input[i]) {
            return;
        }

        res.first += check(s, cnt[i]);
    }

    q.push(res);
    while ((int)q.size() > n) {
        q.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> input[i];

        for (size_t j = 0; j < input[i].size(); j++) {
            char c = input[i][j];
            cnt[i][c - 'A']++;
        }
    }

    string s = "   ";

    for (s[0] = 'A'; s[0] <= 'Z'; s[0]++) {
        int h1 = s[0] - 'A' + 1;
        add(s.substr(0, 1), h1);

        for (s[1] = 'A'; s[1] <= 'Z'; s[1]++) {
            int h2 = h1 * BASE + s[1] - 'A' + 1;
            add(s.substr(0, 2), h2);

            for (s[2] = 'A'; s[2] <= 'Z'; s[2]++) {
                int h3 = h2 * BASE + s[2] - 'A' + 1;
                add(s, h3);

                /*
                for (s[3] = 'A'; s[3] <= 'Z'; s[3]++) {
                    int h4 = h3 * BASE + s[3] - 'A' + 1;
                    add(s, h4);
                }
                */
            }
        }
    }

    while (!q.empty()) {
        cout << unhash(q.top().second) << endl;
        q.pop();
    }

    return 0;
}
