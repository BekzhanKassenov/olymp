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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int cnt[MAXM][26];
string input[MAXM];

priority_queue <pair <int, string> > q;

bool subword(int c[], int w) {
    for (int i = 0; i < 26; i++) {
        if (c[i] > cnt[w][i]) {
            return false;
        }
    }

    return true;
}

void enqueue(const string& s) {
    static int cnt[26];
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }

    for (char c : s) {
        cnt[c - 'A']++;
    }

    int score = 0;
    for (int i = 0; i < m; i++) {
        score += subword(cnt, i);
    }

    q.emplace(score, s);
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

    for (char c = 'A'; c <= 'Z'; c++) {
        enqueue(string(1, c));
    }

    vector <string> res;
    while (n) {
        string cur = q.top().second;
        q.pop();
        bool add = true;
        for (int i = 0; i < m; i++) {
            if (input[i] == cur) {
                add = false;
            }
        }

        if (add) {
            res.emplace_back(cur);
            n--;
        }

        for (char c = 'A'; c <= 'Z'; c++) {
            enqueue(cur + c);
        }
    }

    for (const string& s : res) {
        cout << s << endl;
    }

    return 0;
}
