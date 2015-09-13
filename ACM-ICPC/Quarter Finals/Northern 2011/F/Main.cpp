/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "flat"

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

int n, c;
int area;
string name;
int rooms, bedrooms;
double total;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> area >> name;

        rooms += area;

        if (name == "balcony") {
            total += (area / 2.0);
        } else {
            total += area;
        }

        if (name == "bedroom") {
            bedrooms += area;
        }
    }

    cout << rooms << endl;
    cout << bedrooms << endl;

    cout.precision(10);
    cout << fixed << total * c << endl;

    return 0;
}
