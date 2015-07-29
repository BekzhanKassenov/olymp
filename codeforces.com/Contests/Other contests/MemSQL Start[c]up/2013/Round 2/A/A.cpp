/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <climits>
#include <bitset>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back
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
inline T abs(T n) {
    return (n < 0 ? -n : n);
}

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector <double> a(26);
vector <int> q(26);
string s;
int n;
int max() {
    int tmp = 0;

    for (int i = 0; i < 26; i++) {
        if (a[tmp] < a[i])
            tmp = i;
    }
    
    return tmp;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

    getline(cin, s);

    cin >> n;

    vector <int> res(26);

    for (int i = 0; i < (int)s.size(); i++) {
        a[s[i] - 'a']++;
    }

    int tmp = 0;

    for (int i = 0; i < 26; i++) {
        q[i] = a[i];
        if (a[i])
            tmp++;
    }

    if (tmp > n) {
        cout << -1;
        return 0;
    }

    int c = 0;

    for (int i = 0; i < 26; i++) {
        if (a[i])
            c++, res[i]++;
    }

    while (c < n) {
        c++;
        int i = max();

        a[i] = (a[i] * res[i]) / (res[i] + 1);
        res[i]++;
    }

    tmp = 0;

    for (int i = 0; i < 26; i++) {
        if (res[i]) {
          tmp = i;
          break;
        }
    }


    for (int i = 0; i < 26; i++) {
        if (res[i]) {
            if ((q[tmp + res[tmp] - 1]) / res[tmp] < (q[i] + res[i] - 1) / res[i])
                tmp = i;
        }
    }

    cout << (q[tmp] + res[tmp] - 1) / res[tmp] << endl;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j <res[i]; j++)
            cout << (char)(i + 'a');

     cout << endl;

}