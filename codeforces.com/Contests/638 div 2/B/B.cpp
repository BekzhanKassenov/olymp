/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/
 
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>
 
using namespace std;
 
#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()
 
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
 
const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 110;
 
template <typename T>
inline T sqr(T n) {
  return n * n;
}
 
int n, k;
int a[MAXN];
 
int main() {
#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif
 
  int T;
  cin >> T;
 
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
 
    sort(a, a + n);
    int len = unique(a, a + n) - a;
    if (len > k) {
      cout << -1 << endl;
    } else {
      cout << n * k << endl;
      for (int i = 0; i < n * k; i++) {
        cout << a[i % k] << ' ';
      }
      cout << endl;
    }
  }
 
  return 0;
}
