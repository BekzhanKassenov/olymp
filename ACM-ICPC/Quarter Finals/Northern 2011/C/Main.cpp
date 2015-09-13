/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "cube"

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

map <char, int> Map;
string s[6];
char faces[6];
int last;
map <pair <char, char>, int> Map1;

char get_other(const string& str) {
    bool used[6];
    memset(used, false, sizeof used);

    for (char c: str) {
        for (int i = 0; i < 6; i++) {
            if (faces[i] == c && !used[i]) {
                used[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        if (!used[i]) {
            return faces[i];
        }
    }

    return -1;
}

int p[3][6] = {
    {0, 4, 1, 2, 3, 5},
    {3, 0, 2, 5, 4, 1},
    {4, 1, 0, 3, 5, 2}
};

vector <int> apply(const vector <int>& vec, int n) {
    vector <int> res(6);
    for (int i = 0; i < 6; i++) {
        res[i] = vec[p[n][i]];
    }

    return res;
}

set <vector <int> > used;
void get_lex_min(const vector <int>& vec) {
    if (used.count(vec)) {
        return;
    }

    used.insert(vec);

    for (int i = 0; i < 3; i++) {
        vector <int> temp = vec;
        for (int j = 0; j < 3; j++) {
            temp = apply(temp, i);
            get_lex_min(temp);
        }
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    for (int i = 0; i < 6; i++) {
        cin >> s[i];
        for (char c: s[i]) {
            Map[c]++;
        }
    }

    bool ok = true;
    for (const auto& it: Map) {
        if (it.second % 5 != 0) {
            ok = false;
        }
    }

    if (!ok) {
        puts("Impossible");
        return 0;
    }

    for (const auto& it: Map) {
        for (int j = 0; j < it.second / 5; j++) {
            faces[last++] = it.first;
        }
    }

    for (int i = 0; i < 6; i++) {
        char c1 = s[i][0];
        char c2 = get_other(s[i]);
        Map1[make_pair(min(c1, c2), max(c1, c2))]++;
    }

    /*
    for (const auto& it: Map1) {
        printf("(%d, %d), %d\n", it.first.first, it.first.second, it.second);
    }
    */

    vector <pair <int, int> > p;
    for (const auto& it: Map1) {
        if (it.second % 2 != 0) {
            puts("Impossible");
            return 0;
        }

        for (int j = 0; j < it.second / 2; j++) {
            p.push_back(it.first);
        }
    }

    vector <pair <int, int> > p1;
    p1.emplace_back(0, 5);
    p1.emplace_back(1, 3);
    p1.emplace_back(2, 4);

    sort(all(p1));

    set <vector <int> > ans;
    do {
        vector <int> temp(6);
        for (int mask = 0; mask < (1 << 3); mask++) {
            for (int i = 0; i < 3; i++) {
                if (mask & (1 << i)) {
                    temp[p1[i].first] = p[i].first;
                    temp[p1[i].second] = p[i].second;
                } else {
                    temp[p1[i].first] = p[i].second;
                    temp[p1[i].second] = p[i].first;
                }
            }
        }

        used.clear();
        get_lex_min(temp);
        if (!used.empty()) {
            ans.insert(*used.begin());
        }
    } while (next_permutation(all(p1)));

    auto it = ans.begin();
    for (int i = 0; i < 2 && it != ans.end(); it++) {
        for (auto x: *it) {
            printf("%c", x);
        }

        puts("");
    }

    return 0;
}
