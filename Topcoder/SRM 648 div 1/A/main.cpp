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

class AB {
public:
    bool decreaseByOne(string& s) {
        for (size_t i = 0; i + 1 < s.size(); i++) {
            if (s[i] == 'A' && s[i + 1] == 'B') {
                swap(s[i], s[i + 1]);
                return true;
            }
        }

        return false;
    }
    
    string createString(int N, int K) {
        string s;
        s.append(N, ' ');

        for (int i = 1; i < N; i++) {
            int cnt = i * (N - i);
            for (int j = 0; j < N; j++) {
                s[j] = 'A' + (j >= i);
            }

            while (cnt != K) {
                if (!decreaseByOne(s)) {
                    break;
                }

                cnt--;
            }

            if (cnt == K) {
                return s;
            }
        }

        return "";
    }
};

int main() {
    AB a;
    cout << a.createString(5, 8) << endl;
}
