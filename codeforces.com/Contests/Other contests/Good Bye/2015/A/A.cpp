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

int months[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n;
string s;

struct Date {
    int day, month;
    int weekday;

    Date() :
        day(0),
        month(0),
        weekday(4) { }

    bool next() {
        day++;

        if (day == months[month]) {
            day = 0;
            month++;
        }

        weekday++;
        weekday %= 7;

        return month != 12;
    }
};  

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    cin >> n;
    getline(cin, s);

    if (s == " of week") {
        n--;

        Date d;

        int ans = 0;
        do {
            if (d.weekday == n) {
                ans++;
            }
        } while (d.next());

        cout << ans << endl;

    } else {
        int ans = 0;

        for (int i = 0; i < 12; i++) {
            if (months[i] >= n) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
