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

vector <int> mapping[10] = { 
                             {},              // 0
                             {},              // 1
                             {2},             // 2
                             {3},             // 3
                             {3, 2, 2},       // 4
                             {5},             // 5
                             {5, 3},          // 6
                             {7},             // 7
                             {7, 2, 2, 2},    // 8
                             {7, 3, 3, 2}     // 9
                           };

int n;
char s[30];
vector <int> result;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    scanf("%d\n", &n);
    gets(s);

    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < mapping[s[i] - '0'].size(); j++) {
            result.push_back(mapping[s[i] - '0'][j]);
        }
    }

    sort(all(result));
    reverse(all(result));

    for (size_t i = 0; i < result.size(); i++) {
        printf("%d", result[i]);
    }

    puts("");
    
    return 0;
}
