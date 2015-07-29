#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 2050;

int n;
int dist[MAXN][MAXN];
vector < pair <int, pair<int, int> > > v;
bool found = false;
int test = 0;
int edges;
int e1, e2, ed;

int main() {
freopen("in","r",stdin);
freopen("out1","w",stdout);
while (scanf("%d", &n) == 1) {
test++;
if (test > 1)
printf("\n");

v.clear();
for (int i = 1; i <= n; i++)
for (int j = 1; j <= n; j++) {
scanf("%d", &dist[i][j]);
if (i < j)
v.push_back(make_pair(dist[i][j], make_pair(i, j)));
}

sort(v.begin(), v.end());

edges = 0;

for (int i = 0; i < (int) v.size(); i++) {
int a = v[i].second.first, b = v[i].second.second;
int d = v[i].first;
found = false;
for (int j = 0; j < i; j++) {
int from = v[j].second.first, to = v[j].second.second;
if (from == b)
swap(a, b);
else if (to == a)
swap(from, to);
else if (to == b) {
swap(a, b);
swap(from, to);
}
if (from != a)
continue;
if (d > dist[from][to] && dist[to][b] <= d - dist[from][to]) {
if (to == b)
continue;
found = true;
printf("%d %d %d\n", to, b, d - dist[from][to]);
e1 = to; e2 = b; ed = d - dist[from][to];
edges++;
break;
}
}
if (!found) {
if (a == b)
continue;
printf("%d %d %d\n", a, b, d);
e1 = a; e2 = b; ed = d;
edges++;
}
if (edges == n)
break;
}
for (int i = edges + 1; i <= n; i++)
printf("%d %d %d\n", e1, e2, ed);
}
return 0;
}