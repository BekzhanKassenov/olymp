/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "china"

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

struct BigInt {
    vector <int> nmb;

    BigInt() {
        nmb.push_back(0);
    }      

    BigInt(const string& s) {
        nmb.reserve(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            nmb.push_back(s[i] - '0');
        }
    }

    int mod2() {
        return (nmb[0] % 2);
    }

    int mod4() {
        if (nmb.size() > 1u)
            return (nmb[1] * 10 + nmb[0]) % 4;

        return nmb[0] % 4;
    }

    void operator -= (int k) {
        nmb[0] -= k;

        for (size_t i = 0; i < nmb.size(); i++) {
            if (nmb[i] < 0) {
                nmb[i] += 10;
                nmb[i + 1]--;
            }
        }

            
        while (!nmb.empty() && nmb.back() == 0)
            nmb.pop_back();

        if (nmb.empty())
            nmb.push_back(0);   
    }

    void div2() {
        vector <int> temp;

        int cur = 0;

        for (int i = nmb.size() - 1; i >= 0; i--) {
            cur *= 10;
            cur += nmb[i];
            temp.push_back(cur / 2);
            cur %= 2;
        }

        while (cur > 1) {
            temp.push_back(cur / 2);
            cur %= 2;
        }

        reverse(all(temp));

        while (!temp.empty() && temp.back() == 0)
            temp.pop_back();

        if (temp.empty())
            temp.push_back(0);

        nmb = temp;
    }

    void print() {
        for (int i = nmb.size() - 1; i >= 0; i--)
            cout << nmb[i];
        cout << endl;   
    }
};

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    string s;
    cin >> s;

    BigInt a(s);

    if (a.mod2() == 1) {
        a.div2();
    } else if (a.mod4() == 2) {
        a.div2();
        a -= 2;
    } else {
        a.div2();
        a -= 1;
    }

    a.print();

    return 0;
}

