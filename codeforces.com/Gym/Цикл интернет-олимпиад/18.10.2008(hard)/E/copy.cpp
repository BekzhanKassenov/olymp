/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "game"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 210;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, mx;
string s[MAXN];
set <string> input;
vector <string> substrings;
vector <bool> win;

int main() {
#ifdef Local
    double start = clock();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        mx = max(mx, (int)s[i].size());
        input.insert(s[i]);
    }

    for (int i = 0; i < n; i++) {
        for (size_t x = 0; x < s[i].size(); x++) {
            for (size_t y = x; y < s[i].size(); y++) {
                substrings.push_back(s[i].substr(x, y - x + 1));
            }
        }
    }

    sort(all(substrings));
    substrings.resize(unique(all(substrings)) - substrings.begin());
    win.resize(substrings.size());

    for (int len = mx; len > 0; len--) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= (int)s[i].size() - len; j++) {
                string temp = s[i].substr(j, len);

                int pos = lower_bound(all(substrings), temp) - substrings.begin();

                if (input.count(temp)) {
                    win[pos] = true;
                    continue;
                }

                bool found = false;
                for (char c = 33; c <= 126 && !found; c++) {
                    string temp1 = c + temp;
                    int pos = lower_bound(all(substrings), temp1) - substrings.begin();

                    if (pos == (int)substrings.size() || substrings[pos] != temp1) {
                        continue;
                    }

                    if (!win[pos]) {
                        found = true;
                    }
                }

                for (char c = 33; c <= 126 && !found; c++) {
                    string temp1 = temp;
                    temp1.append(1, c);
                    int pos = lower_bound(all(substrings), temp1) - substrings.begin();

                    if (pos == (int)substrings.size() || substrings[pos] != temp1) {
                        continue;
                    }

                    if (!win[pos]) {
                        found = true;
                    }
                }

                win[pos] = found;
            }
        }
    }

    vector <string> ans;
    for (char c = 33; c <= 126; c++) {
        string temp;
        temp.append(1, c);

        int pos = lower_bound(all(substrings), temp) - substrings.begin();

        if (pos == (int)substrings.size() || substrings[pos] != temp) {
            continue;
        }

        if (!win[pos]) {
            ans.push_back(temp);
        }
    }

    if (ans.empty()) {
        cout << "Second" << endl;
        return 0;
    }

    cout << "First" << endl;
    for (auto& it: ans) {
        cout << it;
    }
    cout << endl;

#ifdef Local
    cerr << "WIN: " << win.size() << endl;
    cerr << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

