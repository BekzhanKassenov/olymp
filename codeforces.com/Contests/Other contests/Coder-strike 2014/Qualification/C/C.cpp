/****************************************
**     Solution by Bekzhan Kassenov    **
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

int a[4], b[4];

bool check_first() {
    if (a[0] > b[2] && b[1] > a[3] && 
        a[0] > b[3] && b[1] > a[2])
        return true;

    if (b[0] > a[2] && a[1] > b[3] &&
        b[0] > a[3] && a[1] > b[2])
        return true;

    return false;
}

bool check_second() {
    if (((a[0] < b[2] && b[1] < a[3]) || 
        (a[0] < b[3] && b[1] < a[2])) &&
        ((b[0] < a[2] && a[1] < b[3]) ||
        (b[0] < a[3] && a[1] < b[2])))
        return true;


    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    for (int i = 0; i < 4; i++)
        cin >> a[i] >> b[i];

    if (check_first())
        cout << "Team 1" << endl;
    else if (check_second())
        cout << "Team 2" << endl;
    else
        cout << "Draw";

    return 0;
}
