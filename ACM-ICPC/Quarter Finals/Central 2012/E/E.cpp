/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int cnt[10];

void remake(int n) {
    if (n == 0)
        cnt[0]++;

    while (n) {
        cnt[n % 10]++;
        n /= 10;
   }
}

bool make(int n) {
    if (n == 0) {
        cnt[0]--;

        if (cnt[0] >= 0)
            return true;

        cnt[0]++;
        return false;   
    }

    int cop = n;

    bool flag = false;

    while (cop) {
        cnt[cop % 10]--;
        if (cnt[cop % 10] < 0)
            flag = true;

        cop /= 10;
    }

    if (flag) {
        remake(n);
        return false;
    }

    return true;
}

bool check() {
    for (int i = 0; i < 10; i++)
        if (cnt[i] != 0)    
            return false;

    return true;
}

bool try_to_make(int gl, int nmb, int &cur) {
    //cout << gl << ' ' << nmb << ' ' << cur << endl;
    if (gl == 4) {
        int t = nmb * cur;
        if (make(t) && check())
            return true;

        remake(t);
        return false;
    }

    for (int i = (gl ^ 0); i < 10; i++) {
        if (cnt[i]) {
            cnt[i]--;

            if (make(nmb * i)) {
                cur *= 10;
                cur += i;

                if (make(nmb * cur) && check())
                    return true;

                remake(nmb * cur);

                if (try_to_make(gl + 1, nmb, cur))
                    return true;

                cur /= 10;
            }

            remake(nmb * i);
            cnt[i]++;
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 10; i++)
        cin >> cnt[i];

    int res = 0;

    for (int first = 0; first < 10000; first++) {
        if (make(first)) {
            cout << first << endl;
            if (try_to_make(0, first, res)) {
                cout << first << endl << res << endl;
                return 0;
            }
        }
    }
        
    return 0;
}
