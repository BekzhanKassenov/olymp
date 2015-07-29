/****************************************
**          Solution by NU #2          **
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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

void println(const vector <pair <char, int> >& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i].first << ' ' << vec[i].second << endl;
    }
    cout << endl;
}

int n;
char s[MAXN];
vector <pair <char, int> > a;

void compress(vector <pair <char, int> >& a) {
    for (size_t i = 0; i + 1 < a.size(); i++) {
        if (a[i].first == a[i + 1].first) {
            a[i].second += a[i + 1].second;
            a.erase(a.begin() + i + 1);
            i--;
        }
    }
}

int solve(vector <pair <char, int> >& a) {
    int res = 0;
    compress(a);

    for (size_t i = 0; i + 1 < a.size(); i++) {
        if (a[i].first == 'F' && a[i + 1].first == 'A') {
            res = a[i].second * a[i + 1].second;
            swap(a[i], a[i + 1]);
            return res + solve(a);
        }
    }

    for (size_t i = 0; i + 2 < a.size(); i++) {
        if (a[i].first == 'F' && a[i + 1].first == 'N' && a[i + 2].first == 'A') {
            int nf = a[i].second;
            int nn = a[i + 1].second;
            int na = a[i + 2].second;

            if (nf > na) {
                res = na * (nf + nn);
                swap(a[i + 2], a[i + 1]);
                swap(a[i + 1], a[i]);
            } else {
                res = nf * (nn + na);
                swap(a[i], a[i + 1]);
                swap(a[i + 1], a[i + 2]);
            }

            return res + solve(a);
        }
    }

    return 0;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &n);

    gets(s);

    a.push_back(make_pair(s[0], 1));
    for (int i = 1; s[i]; i++) {
        if (s[i] == a.back().first) {
            a.back().second++;
        } else {
            a.push_back(make_pair(s[i], 1));
        }
    }


    printf("%d\n", solve(a));
    println(a);
    return 0;
}
