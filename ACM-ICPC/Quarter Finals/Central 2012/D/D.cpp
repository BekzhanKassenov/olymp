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

int d[100010];
int mind[100010];
int index[100010];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, ans = INF;

    cin >> n;

    string s;

    getline(cin, s);
    getline(cin, s);

    bool flag = false;

    for (int i = 0; i < n; i++) {
        d[i + 1] = d[i] + (s[i] == '*');

        mind[i + 1] = 2 * d[i] - i - 1;
        
        if (i > 1 && s[i] == s[i - 1] && s[i] == '*')
            flag = true;

        if (mind[i + 1] > mind[index[i]]) 
            index[i + 1] = index[i];
        else
            index[i + 1] = i + 1; 
    }

    if (!flag) {
        cout << d[n] << endl;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!flag) {
                    cout << i + 1 << endl;
                    flag = true;
                } else
                    cout << "Ctrl+" << i + 1 << endl;
            }
        }

        return 0;
    }

    int l = 0, r = 0;
    
    for (int i = 2; i <= n; i++) {
        if (ans > i - index[i] + 1 - 2 * d[i] + 2 * d[index[i] - 1] + d[n]) {
            ans = i - index[i] + 1 - 2 * d[i] + 2 * d[index[i] - 1] + d[n]; 
            r = i;
            l = index[i];
        }
    }

/*    for (int i = 0; i <= n; i++) {
        cout << d[i] << " "  << index[i] << ' ' << mind[i] << endl;
    }       */

    cout << ans + 2 << endl << l << endl << "Shift+" << r << endl;

    for (int i = 0; i < n; i++) {
        if (i >= l - 1 && i <= r - 1 && s[i] == '.')
            cout << "Ctrl+" << i + 1 << endl;
        else { 
            if ((i < l - 1 || i > r - 1) && s[i] == '*') 
                cout << "Ctrl+" << i + 1 << endl;
        }
    }

    return 0;
}
