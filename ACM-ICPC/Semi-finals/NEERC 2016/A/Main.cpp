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
const string space = " ";

template <typename T>
inline T sqr(T n) {
    return n * n;
}

string line;

bool isAbbr(const string& s) {
    if (s.size() < 2u) {
        return false;
    }

    if (!isupper(s[0])) {
        return false;
    }

    for (size_t i = 1; i < s.size(); i++) {
        if (!islower(s[i])) {
            return false;
        }
    }

    return true;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (getline(cin, line)) {
        vector <string> tokens;
        for (size_t i = 0; i < line.size(); i++) {
            if (tokens.empty() || (bool)isalpha(tokens.back().back()) != (bool)isalpha(line[i])) {
                tokens.push_back(string(1, line[i]));
            } else {
                tokens.back().push_back(line[i]);
            }
        }

        vector <string> result;
        size_t pos = 0;
        while (pos < tokens.size()) {
            bool justAdd = !isAbbr(tokens[pos]);
            justAdd |= (pos + 2 >= tokens.size() || tokens[pos + 1] != space || !isAbbr(tokens[pos + 2]));

            if (justAdd) {
                result.emplace_back(tokens[pos]);
                pos++;
            } else {
                size_t abbrStart = pos;
                pos++;
                while (pos + 1 < tokens.size()) {
                    if (tokens[pos] == space && isAbbr(tokens[pos + 1])) {
                        pos += 2;
                    } else {
                        break;
                    }
                }

                string abbr;
                for (size_t i = abbrStart; i < pos; i += 2) {
                    abbr += tokens[i][0];
                }

                result.emplace_back(abbr);
                result.emplace_back(" (");
                for (size_t i = abbrStart; i < pos; i++) {
                    result.emplace_back(tokens[i]);
                }
                result.emplace_back(")");
            }
        }

        for (const string& s: result) {
            cout << s;
        }
        cout << endl;
    }
    
    return 0;
}
