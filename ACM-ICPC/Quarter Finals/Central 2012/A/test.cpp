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

void hanoi(int a, int b, int c, int n) {
    if (n > 0) {
        hanoi(a, c, b, n - 1);
        cout << "From " << a << " to " << b << endl;
        hanoi(c, b, a, n - 1);
    }
}

int main() {
    int n;
    cin >> n;

    hanoi(1, 2, 3, n);
    return 0;
}
