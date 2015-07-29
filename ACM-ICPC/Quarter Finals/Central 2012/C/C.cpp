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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    cin >> n;

    int a[24] = {1, 2, 4, 8, 16, 23, 46, 29, 58, 116, 223, 446, 289, 578, 1156, 1223, 2446, 2489, 4789, 5789, 11578, 12356, 12247, 24449};

    int b[6] = {48889, 77789, 155578, 111356, 122227, 244445};

    if (n <= 24) {
        cout << a[n - 1];
        return 0;
    }

    n -= 24;

    cout << b[(n - 1) % 6];

    return 0;
}
