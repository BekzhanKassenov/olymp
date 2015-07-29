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

class TaroJiroGrid {
public:
    int n;
    string w, b;

    bool check(const vector <string>& s) {
        for (int j = 0; j < n; j++) {
            int cnt = 1;
            char cur = s[0][j];

            for (int i = 1; i < n; i++) {
                if (s[i][j] == cur)
                    cnt++;
                else {
                    if (cnt > n / 2)
                        return false;

                    cnt = 1;
                    cur = s[i][j];
                }
            }                                                                     

            if (cnt > n / 2)
                return false;
        }

        return true;
    }

    int getNumber(vector <string> grid) {
        n = grid.size();

        if (check(grid))
            return 0;

        w.append(n, 'W');
        b.append(n, 'B');

        int ans = 100;
        
        for (int i = 0; i < n; i++) {
            string pri = grid[i];
            grid[i] = w;
            if (check(grid))
                return 1;

            for (int j = i + 1; j < n; j++) {
                string prj = grid[j];
                grid[j] = w;

                if (check(grid))
                    ans = min(ans, 2);

                grid[j] = b;

                if (check(grid))
                    ans = min(ans, 2);

                grid[j] = prj;
            }

            grid[i] = b;
            if (check(grid))
                return 1;

            for (int j = i + 1; j < n; j++) {
                string prj = grid[j];
                grid[j] = w;

                if (check(grid))
                    ans = min(ans, 2);

                grid[j] = b;

                if (check(grid))
                    ans = min(ans, 2);

                grid[j] = prj;
            }
        }

        return ans;
    }
};

int main() {
    return 0;
}