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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
string s, t;
vector <string> words;
set <string> bad;
map <string, int> cnt1;
map <pair <string, string>, int> cnt2;

void split(string str, vector <string>& vec) {
    string cur;

    for (auto c: str) {
        if (isalpha(c)) {
            cur += tolower(c);
        } else if (!cur.empty()) {
            vec.push_back(cur);
            cur.clear();
        }
    }

    if (!cur.empty()) {
        vec.push_back(cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> n;

    getline(cin, s);
    
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        split(s, words);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> s;
        bad.insert(s);
    }

    vector <string> temp;

    for (string str: words) {
        if (!bad.count(str)) {
            temp.push_back(str);
        }
    }

    words.swap(temp);

    for (string str: words) {
        cnt1[str]++;
    }

    for (size_t i = 0; i + 1 < words.size(); i++) {
        cnt2[make_pair(min(words[i], words[i + 1]), max(words[i], words[i + 1]))]++;
    }

    int m;
    cin >> m;

    cout.precision(14);
    cout << fixed;

    for (int i = 0; i < m; i++) {
        cin >> s >> t;

        if (!cnt1.count(s) || !cnt1.count(t)) {
            cout << 0 << endl;
            continue;
        } else {
            double num = cnt2[make_pair(min(s, t), max(s, t))] * sqr(double(words.size()));
            double den = (1.0 * cnt1[s] * cnt1[t]) * double(words.size() - 1);

            cout << num / den << endl;
        }
    }

    return 0;
}
