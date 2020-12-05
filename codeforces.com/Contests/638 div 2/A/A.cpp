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
 
template <typename T>
inline T sqr(T n) {
  return n * n;
}
 
int main() {
#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif
 
  int T;
  cin >> T;
 
  while (T--) {
    int n;
    cin >> n;
 
    int rhs = (1 << n);
    int lhs = (1 << n) - 2;
    for (int i = 0; i < (n / 2) - 1; i++) {
      lhs -= 1 << (i + 1);
      rhs += 1 << (i + 1);
    }
 
    cout << rhs - lhs << endl;
  }
 
  return 0;
}
