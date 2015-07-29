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

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
    #endif

  	ll n;
  	cin >> n;

  	ll k = 3;

  	ll t = n;

  	while (n % 3 == 0) {
  		n /= 3;
  		k *= 3;
  	}

  	cout << t / k + 1;

    return 0;
}