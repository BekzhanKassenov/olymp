#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int MAXN = 100010;

int n, d, a[MAXN];
map <int, vector <int> > Map;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &d);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        Map[a[i]].push_back(i);
    }



    return 0;
}
