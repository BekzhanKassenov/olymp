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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, m;
string names[MAXN];
string senders[MAXN];
string msgs[MAXN];
set <int> options[MAXN];
bool used[MAXN];

void get_options(int pos) {
    options[pos].clear();
    for (int i = 0; i < n; i++) {
        options[pos].insert(i);
    }

    auto doerase = [&](const string& s) {
        options[pos].erase(lower_bound(names, names + n, s) - names);
    };

    string token;
    for (size_t i = 0; i < msgs[pos].size(); i++) {
        char c = msgs[pos][i];
        if (isalpha(c) || isdigit(c)) {
            token.push_back(c);
        } else {
            if (!token.empty()) {
                if (binary_search(names, names + n, token)) {
                    doerase(token);
                }
            }

            token.clear();
        }
    }

    if (!token.empty()) {
        if (binary_search(names, names + n, token)) {
            doerase(token);
        }
    }

    if (pos > 0 && senders[pos - 1] != "?") {
        doerase(senders[pos - 1]);
    }

    if (pos + 1 < m && senders[pos + 1] != "?") {
        doerase(senders[pos + 1]);
    }
}

bool model(queue <int>& q) {
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if (options[num].empty()) {
            return false;
        }

        int chosen = *options[num].begin();
        senders[num] = names[chosen];

        auto doit = [&] (int pos) {
            options[pos].erase(chosen);
            if (senders[pos] == "?") {
                if (options[pos].empty()) {
                    return false;
                }
                if (options[pos].size() == 1u && !used[pos]) {
                    q.push(pos);
                    used[pos] = true;
                }
            }

            return true;
        };

        if (num > 0) {
            if (!doit(num - 1)) {
                return false;
            }
        }

        if (num + 1 < m) {
            if (!doit(num + 1)) {
                return false;
            }
        }
    }

    return true;
}


void solve() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    sort(names, names + n);

    cin >> m;

    memset(used, false, sizeof(int) * (m + 1));
    cin.ignore(1, '\n');
    for (int i = 0; i < m; i++) {
        senders[i].clear();
        int ch;
        while ((ch = cin.get()) != ':') {
            senders[i].push_back(ch);
        }

        getline(cin, msgs[i]);
    }

    queue <int> q;
    for (int i = 0; i < m; i++) {
        get_options(i);
        if (options[i].size() == 1u) {
            q.push(i);
            used[i] = true;
        }
    }

    if (!model(q)) {
        cout << "Impossible" << endl;
        return;
    }

    for (int i = 0; i < m; i++) {
        if (!used[i] && senders[i] == "?") {
            q.push(i);
            used[i] = true;
        }
    }

    if (!model(q)) {
        cout << "Impossible" << endl;
        return;
    }

    for (int i = 0; i < m; i++) {
        cout << senders[i] << ':' << msgs[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
