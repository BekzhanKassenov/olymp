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

class SubdividedSlimes {
public:
    int needCut(int S, int M) {
        priority_queue <int> q;

        q.push(S);

        int sum = 0;
        int ans = 0;

        while (!q.empty() && sum < M) {
            ans++;

            int cur = q.top();
            q.pop();
            int x = cur / 2;
            int y = cur - x;

            sum += x * y;

            if (x > 1) {
                q.push(x);
            }

            if (y > 1) {
                q.push(y);
            }
        }

        if (sum >= M) {
            return ans;
        }

        return -1;
    }
};

SubdividedSlimes s;

int main() {

    cout << s.needCut(3, 2) << endl;
    cout << s.needCut(3, 3) << endl;
    cout << s.needCut(3, 4) << endl;
    cout << s.needCut(765, 271828) << endl;

    return 0;
}
