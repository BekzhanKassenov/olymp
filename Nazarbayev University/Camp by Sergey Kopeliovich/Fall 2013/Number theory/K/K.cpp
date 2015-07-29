#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
const int INF = (int)1e9;

ll pow_mod(ll a, int st, ll MOD) {
    if (st == 0)
        return 1;

    if (st & 1) 
        return (pow_mod(a, st - 1, MOD) * a) % MOD;

    ll b = pow_mod(a, st >> 1, MOD);
    return (b * b) % MOD;
}

int main() {
    freopen("logging.in", "r", stdin);
    freopen("logging.out", "w", stdout);

    int p, b, n;
    
    while (cin >> p >> b >> n) {
        int k = sqrt(p) + 1;

        map <int, int> Map;

        for (int i = k; i >= 0; i--) 
            Map[pow_mod(b, k * i, p)] = i;

        int ans = INF;

        for (int i = 0; i <= k; i++) {
            int z = pow_mod(b, i, p);
            z = pow_mod(z, p - 2, p) * n % p;

            if (Map.count(z))
                ans = min(ans, k * Map[z] + i);
        }

        if (ans == INF)
            cout << "no solution";
        else
            cout << ans;
        cout << endl;   
    }

}
