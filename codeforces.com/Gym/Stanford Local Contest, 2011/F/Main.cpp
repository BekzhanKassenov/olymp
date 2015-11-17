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

const vector <int> cellsOf[18] = {
    {1},    // 1
    {1},    // 2
    {1, 3}, // 3
    {2},    // 4
    {2, 3}, // 5
    {2, 6}, // 6
    {3, 4}, // 7
    {4},    // 8
    {4, 8}, // 9
    {5},    // 10
    {5, 6}, // 11
    {5},    // 12
    {6, 7}, // 13
    {7, 8}, // 14
    {7},    // 15
    {8, 9}, // 16
    {9},    // 17
    {9}     // 18
};

int taken;
int takenEdges[11];

int take(int edge) {
    assert(!(taken & (1 << edge)));

    taken |= 1 << edge;

    int ans = 0;
    for (int cell: cellsOf[edge]) {
        takenEdges[cell]++;

        if (takenEdges[cell] == 3) {
            ans++;
        }
    }

    return ans;
}

void untake(int edge) {
    assert(taken & (1 << edge));

    taken ^= 1 << edge;
    for (int cell: cellsOf[edge]) {
        takenEdges[cell]--;
    }
}

int n;

bool calced[2][1 << 18];
pair <int, int> dp[2][1 << 18];

bool better(int turn, pair <int, int> a, pair <int, int> b) {   
    if (b == make_pair(-1, -1)) {
        return true;
    }

    if (turn == 1) {
        swap(a.first, a.second);
        swap(b.first, b.second);
    }

    if (b.first <= b.second) {
        if (a.first > a.second) {
            return true;
        }

        if (a.second - a.first < b.second - b.first) {
            return true;
        }

        return false;
    }

    return a.first - a.second > b.first - b.second;
}

pair <int, int> go(int turn) {
    if (calced[turn][taken]) {
        return dp[turn][taken];
    }

    calced[turn][taken] = true;

    pair <int, int>& ans = dp[turn][taken];
    ans.first = ans.second = -1;

    for (int i = 0; i < 18; i++) {
        if (!(taken & (1 << i))) {
            pair <int, int> temp(0, 0);

            int score = take(i);

            if (turn == 0) {
                temp.first = score;
            } else {
                temp.second = score;
            }

            int next_turn = turn;
            if (score == 0) {
                next_turn ^= 1;
            }

            pair <int, int> ret = go(next_turn);
            temp.first += ret.first;
            temp.second += ret.second;

            if (better(turn, temp, ans)) {
                ans = temp;
            }

            untake(i);
        }
    }

    if (taken == (1 << 18) - 1) {
        ans = make_pair(0, 0);
    }

    return ans;
}

void clear() {
    taken = 0;
    memset(takenEdges, 0, sizeof(takenEdges));
    memset(calced, false, sizeof(calced));
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    while (scanf("%d", &n) == 1 && n != 0) {
        clear();

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            take(x - 1);
        }

        pair <int, int> result = go(0);

        //cerr << result.first << ' ' << result.second << endl;

        if (result.first > result.second) {
            puts("Andy wins");
        } else if (result.first < result.second) {
            puts("Ralph wins");
        } else {
            puts("Draw");
        }
    }
    
    return 0;
}
