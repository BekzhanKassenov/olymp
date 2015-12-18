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
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char a[110][110];
vector <int> tokens[110][110];

bool ok(int x, int y) {
    return 0 <= x && x <= n && 
           0 <= y && y <= n;
}

class BoardEscape {
    bool kill(int i, int j) {
        if (!tokens[i][j].empty()) {
            for (int k = 0; k < 4; k++) {
                int tx = i + dx[k];
                int ty = j + dy[k];

                if (a[tx][ty] == 'E') {
                    return true;
                }
            }
        }

        return false;
    }

    bool can_kill() {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (!tokens[i][j].empty()) {
                    for (int k = 0; k < 4; k++) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];

                        if (a[tx][ty] == 'E') {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    bool solve() {
        int sum = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int x: tokens[i][j]) {
                    sum += x;
                }
            }
        }

        if (sum == 0) {
            return false;
        }

        if (sum % 2 == 1) {
            return can_kill();
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                for (int x: tokens[i][j]) {
                    if (x % 2 == 0 && kill(i, j)) {
                        return true;
                    }
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (!tokens[i][j].empty()) {
                    int val = tokens[i][j][0];
                    tokens[i][j].clear();

                    for (int k = 0; k < 4; k++) {
                        int tx = i + dx[k];
                        int ty = j + dy[k];

                        if (a[tx][ty] != '#' && a[tx][ty] != 'E') {
                            tokens[tx][ty].push_back(val - 1);

                            if (!solve()) {
                                return true;
                            }

                            tokens[tx][ty].pop_back();
                        }
                    }

                    tokens[i][j].push_back(val);
                }
            }
        }

        return false;
    }
public:
    string findWinner(vector <string> s, int k) {
        n = s.size() + 2;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                a[i][j] = '#';
            }
        }

        for (size_t i = 0; i < s.size(); i++) {
            for (size_t j = 0; j < s[i].size(); j++) {
                a[i + 1][j + 1] = s[i][j];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (a[i][j] != 'T') {
                    continue;
                }

                bool found = false;
                for (int k = 0; k < 4; k++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];

                    if (a[tx][ty] != '#') {
                        found = true;
                    }
                }
                
                if (found) {
                    tokens[i][j].push_back(k);
                }
            }
        }

        if (solve()) {
            return "Alice";
        }

        return "Bob";
    }
};

int main() {
    BoardEscape e;
    cout << e.findWinner({"..........................", "......TTT..TTT..T...T.....", ".....T.....T..T.TT.TT.....", "......TTT..TTT..T.T.T.....", ".........T.T.T..T...T.....", "......TTT..T..T.T...T.....", "..........................", "...E#E#E#E#E#E#E#E#E#E#...", "..........................", "......TTT..TTT...TTT......", ".....T........T.T.........", "......TTT.....T..TTT......", ".....T...T...T..T...T.....", "......TTT....T...TTT......", "..........................", "...#E#E#E#E#E#E#E#E#E#E...", "..........................", "....TT...T...T..T.TTT.T...", "...T.....T...T..T.T...T...", "...T.TT..T...TTTT.TT..T...", "...T..T..T...T..T.T.......", "....TT...TTT.T..T.T...T...", ".........................."}, 987654321) << endl;
}