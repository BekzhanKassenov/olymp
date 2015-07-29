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

class PeriodicJumping {
public:
    int minimalTime(int x, vector <int> jumpLengths) {
        ll sum = 0;
        int n = jumpLengths.size();

        for (int i = 0; i < n; i++)
            sum += jumpLengths[i];

        x = abs(x);

        if (sum == x)
            return n;

        if (x == 0)
            return 0;

        if (sum < x) {
            ll nx = x / sum;
            x %= sum;

            if (x == 0)
                return nx * n;

            ll sum1 = nx * sum;

            for (int i = 0; i < n; i++) {
                sum1 += jumpLengths[i];

                if (sum1 == x)
                    return nx * n + i + 1;

                if (sum1 > x) {
                    bool flag = true;
                    for (int j = 0; j < n; j++) {
                        ll temp1 = 2ll * jumpLengths[j];
                        ll temp2 = sum1 + x;

                        if (temp1 > temp2)
                            flag = false;
                    }

                    if (flag)
                        return nx * n + i + 1;
                }
            }

            return -1;
        }

        ll sum1 = jumpLengths[0];

        if (sum1 == x)
            return 1;

        int ans = 1;
        ll mx = jumpLengths[0];
        int tc = 110;

        for (int i = 1 % n; tc--; i = (i + 1) % n) {
            sum1 += jumpLengths[i];
            mx = max(mx, (ll)jumpLengths[i]);
            
            ans++;
            //cout << sum1 << ' ' << i << endl;
            if (sum1 == x)
                return ans;
            
            if (sum1 > x) {
                ll temp1 = 2ll * mx;
                ll temp2 = sum1 + x;

                if (temp1 < temp2)
                    return ans;
            }
        }

        return -1;
    }
};      

int main() {
    PeriodicJumping a;
    int t[] = {2,3,4,500,6,7,8};

    vector <int> temp(t, t + 7); 
    int x = -10;

    cout << a.minimalTime(x, temp);

    return 0;
}
