/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    srand(time(NULL));

    int n = rand() % 1000 + 1;
    int m = rand() % 1000 + 1;

    cout << n << ' ' << m << endl;

    vector <int> anc;
    anc.push_back(1);

    for (int i = 2; i <= n; i++) {
        int pos = rand() % anc.size();
        cout << anc[pos] << ' ' << i << endl;
        anc.push_back(i);
    }

    for (int i = 0; i < m; i++)
        cout << rand() % n + 1 << ' ' << rand() % n + 1 << endl;

    return 0;
}
