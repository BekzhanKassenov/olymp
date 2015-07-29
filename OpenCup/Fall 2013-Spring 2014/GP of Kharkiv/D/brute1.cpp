/****************************************
**         Solution by NU #2           **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

const int MAX_SIZE = 12;

string vars[12] = {"abc", "aba", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"};

bool okay (string a) {
    int n = a.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; i + 2 * j - 1 < n; j++) {
            bool flag = true;
            
            for (int k = 0; k < j; k++)
                if (a[i + k] != a[i + k + j])
                    flag = false;
                    
            if (flag)
                return false;
        }
    }
    
    return true;
}

bool check(int i, int j, int k) {
    int a[3] = {i, j, k};
    
    sort(a, a + 3);
    
    do {
        string s = vars[a[0]] + vars[a[1]] + vars[a[2]];
        
        if (!okay(s))
            return false;
    } while (next_permutation(a, a + 3));
    
    return true;
}

int main() {
#ifdef Local
    freopen("out", "r", stdin);
#endif
    

    string s;
    cin >> s;

    if (okay(s)) {
        cout << "YES";
    } else
        cout << "NO";
    cout << endl;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            for (int k = 0; k < MAX_SIZE; k++)
                if (i != j && j != k && i != k && check(i, j, k)) {
                    cout << 'a' << ' ' << vars[i] << endl;
                    cout << 'b' << ' ' << vars[j] << endl;
                    cout << 'c' << ' ' << vars[k] << endl;
                    cout << endl;
                }
        }
    }

    return 0;
}
