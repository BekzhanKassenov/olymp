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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

class MultiplicationTable2 {
    int expand(const vector <vector <int> >& table, int a, int b) {
        set <int> Set;
        Set.insert(a);

        queue <int> to_add;
        to_add.push(b);

        while (!to_add.empty()) {
            int val = to_add.front();
            to_add.pop();

            set <int> save(Set);

            for (int num: save) {
                if (!Set.count(table[num][val])) {
                    Set.insert(table[num][val]);
                    to_add.push(table[num][val]);
                }

                if (!Set.count(table[val][num])) {
                    Set.insert(table[val][num]);
                    to_add.push(table[val][num]);
                }
            }
        }

        return Set.size();
    }
public:
    int minimalGoodSet(vector <int> table) {
        int n = int(sqrt(table.size()));
        int ans = n;

        vector <vector <int> > t(n, vector <int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                t[i][j] = table[i * n + j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ans = min(ans, expand(t, i, j));
            }
        }

        return ans;
    }
};